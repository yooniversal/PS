//2606

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

int N, M, a, b, cnt;
int chk[1001];
vector<vector<int>> E;

void dfs(int cur) {

	//방문한 노드 표시
	chk[cur] = 1;

	//종료 조건
	//해당 노드에서 움직일 곳이 없을 경우
	for (int i = 0; i < E[cur].size(); i++) {
		if (chk[E[cur][i]] == 0) break;
		if (i == E[cur].size() - 1) {
			return;
		}
	}

	//탐색
	for (int i = 0; i < E[cur].size(); i++)
		if (chk[E[cur][i]] == 0) {
			dfs(E[cur][i]);
		}
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> N >> M;
	E.resize(N + 1);

	//간선 입력
	while (M--) {
		cin >> a >> b;
		E[a].push_back(b);
		E[b].push_back(a);
	}

	for (int i = 1; i <= N; i++)
		sort(E[i].begin(), E[i].end());

	//1번 컴퓨터에서 시작이므로 인자에 1을 넣어준다
	dfs(1);

	//방문된 노드를 센다
	for (int i = 0; i <= N; i++)
		if (chk[i] == 1) cnt++;

	//1번 컴퓨터는 제외해야 하므로 -1
	cout << cnt - 1;

	return 0;
}