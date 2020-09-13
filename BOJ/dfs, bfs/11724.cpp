//11724

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
#define MAX 1001
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

vi node[MAX];
bool chk[MAX];

void dfs(int cur) {
	for (auto& next : node[cur]) {
		if (chk[next]) continue;
		chk[next] = true;
		dfs(next);
	}
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m; cin >> n >> m;
	while (m--) {
		int a, b; cin >> a >> b;
		node[a].push_back(b);
		node[b].push_back(a);
	}

	int ret = 0;
	for (int i = 1; i <= n; i++) {
		if (chk[i]) continue;
		dfs(i); ret++;
	}

	cout << ret;

	return 0;
}