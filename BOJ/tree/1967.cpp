//1167

#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <cmath>
#include <algorithm>
using namespace std;

vector<pair<int, int>> node[100001]; //first: next  second: distance
bool chk[100001];
int ans, re;

void bfs(int s) {
	queue<pair<int, int>> q;
	for (int i = 0; i < node[s].size(); i++) q.push({ node[s][i].first, node[s][i].second });
	chk[s] = true;
	while (!q.empty()) {
		int cur = q.front().first;
		int dist = q.front().second;
		q.pop();
		//cout << "start:" << s << " cur:" << cur << " dist: " << dist << " ans:" << ans << '\n';

		//종료 조건
		if (node[cur].size() <= 1) {
			ans = max(ans, dist);
			if (ans == dist) re = cur;
			continue;
		}

		chk[cur] = true;
		for (int i = 0; i < node[cur].size(); i++) {
			if (!chk[node[cur][i].first]) {
				q.push({ node[cur][i].first, node[cur][i].second + dist });	//다음 노드(node[cur][i].second)의 거리에 현재까지 거리(dist)를 더해줌
				//cout << "???:" << node[cur][i].first << '\n';
			}
		}
	}
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, fir, sec, dist;
	cin >> n;
	for (int i = 0; i < n-1; i++) {
		cin >> fir >> sec >> dist;
		node[fir].push_back({ sec, dist });
		node[sec].push_back({ fir, dist });
	}
	bfs(1);
	memset(chk, false, sizeof(chk));
	//cout << "re:" << re << " ans"<<ans<< '\n';
	bfs(re);

	cout << ans;

	return 0;
}