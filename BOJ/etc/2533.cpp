//2533

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
#include <map>
using namespace std;
#define MAXSIZE 1000001

int n, dp[MAXSIZE][2];
bool visited[MAXSIZE];
vector<int> adj[MAXSIZE];

int dfs(int cur, bool selected) {
	visited[cur] = true;
	if (dp[cur][selected]) return dp[cur][selected];
	if (selected) dp[cur][selected]++;

	for (auto& next : adj[cur]) {
		//방문된 곳은 무시
		if (visited[next]) continue;

		//cur이 얼리어답터 -> 이웃은 둘 중 하나
		if (selected) dp[cur][selected] += min(dfs(next, true), dfs(next, false));
		//cur이 얼리어답터X -> 이웃은 얼리어답터
		else dp[cur][selected] += dfs(next, true);
	}

	visited[cur] = false;
	return dp[cur][selected];
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n;
	for (int i = 0; i < n-1; i++) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	
	int resultT = dfs(1, true);
	int resultF = dfs(1, false);

	//cout << resultT << " " << resultF;
	cout << min(resultT, resultF);

	return 0;
}