//1707

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
#define INF 1000000001
#define MAX 20001
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

vi node[MAX];
int color[MAX];
bool ret = true;

void dfs(int cur) {
	for (auto& next : node[cur]) {
		if (color[next] != -1) {
			if(color[cur] == color[next]) ret = false;
			continue;
		}
		color[next] = color[cur] == 0 ? 1 : 0;
		dfs(next);
	}
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int t; cin >> t;
	while (t--) {
		memset(color, -1, sizeof(color));
		ret = true;
		int n, m; cin >> n >> m;
		for (int i = 0; i < m; i++) {
			int a, b; cin >> a >> b;
			node[a].push_back(b);
			node[b].push_back(a);
		}

		for (int i = 1; i <= n; i++) {
			if (color[i] != -1) continue;
			color[i] = 0;
			dfs(i);
		}

		if (ret) cout << "YES\n";
		else cout << "NO\n";

		for (int i = 1; i <= n; i++)
			node[i].clear();
	}

	return 0;
}