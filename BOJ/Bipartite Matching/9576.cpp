//9576
#include <bits/stdc++.h>
using namespace std;
#define INF 1000000001
#define MAX 1000001
#define MOD 1000000000
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

vi person[1001];
bool chk[1001];
int from[1001];

bool dfs(int cur) {
	for (auto& next : person[cur]) {
		if (chk[next]) continue;
		chk[next] = true;

		if (from[next] == 0 || dfs(from[next])) {
			from[next] = cur;
			return true;
		}
	}
	return false;
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int t; cin >> t;
	while (t--) {
		memset(from, 0, sizeof(from));
		memset(chk, 0, sizeof(chk));
		for (int i = 0; i < 1001; ++i) person[i].clear();

		int n, m; cin >> n >> m;
		for (int i = 1; i <= m; ++i) {
			int a, b; cin >> a >> b;
			for (int j = a; j <= b; ++j)
				person[i].push_back(j);
		}

		int ret = 0;
		for (int i = 1; i <= m; ++i) {
			memset(chk, 0, sizeof(chk));
			if (dfs(i)) ++ret;
		}
		cout << ret << '\n';
	}

	return 0;
}