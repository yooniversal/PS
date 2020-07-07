//1260

#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <vector>
#include <deque>
#include <cmath>
#include <queue>
#include <algorithm>
using namespace std;

int N, M, a, b;
int chk[1001];
vector<int> stack;
deque<int> que;
vector<vector<int>> E;

bool isEnd() {
	for (int i = 1; i <= N; i++)
		if (chk[i] == 0)
			return false;
	return true;
}

void dfs(int cur) {

	//종료 조건
	if (isEnd()) return;

	cout << cur << " ";
	chk[cur] = 1;

	//탐색
	for (int i = 0; i < E[cur].size(); i++)
		if (chk[E[cur][i]] == 0) {
			dfs(E[cur][i]);
		}
}

void bfs(int cur) {
	int tmp = cur;
	//종료 조건
	if (que.empty()) return;

	cout << cur << " ";
	chk[cur] = 1;
	que.pop_back();

	//cur번 Vertex에 이웃한 체크안 된 Vertex를 탐색하고 queue에 push
	//1개만 push 해야하므로 break문 추가
	for (int i = 0; i < E[tmp].size(); i++)
		if (chk[E[tmp][i]] == 0) {
			que.push_front((E[tmp][i]));
			chk[E[tmp][i]] = 1;
		}

	if (!que.empty()) {
		bfs(que.back());
	}
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int V;

	cin >> N >> M >> V;
	E.resize(N + 1);

	//간선 입력
	while (M--) {
		cin >> a >> b;
		E[a].push_back(b);
		E[b].push_back(a);
	}

	for (int i = 1; i <= N; i++)
		sort(E[i].begin(), E[i].end());
	
	dfs(V);
	cout << "\n";
	memset(chk, 0, sizeof(chk));
	que.push_front(V);
	bfs(V);

	return 0;
}