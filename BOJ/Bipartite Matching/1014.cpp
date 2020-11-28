//1014
#include <bits/stdc++.h>
using namespace std;
#define INF 1000000001
#define MAX 80
#define MOD 1000000007
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

int dx[] = { -1,0,1,-1,0,1 }, dy[] = { -1,-1,-1,1,1,1 };
int n, m;
vi person[MAX * MAX + 5];
bool chk[MAX * MAX + 5];
int from[MAX * MAX + 5];

bool OOB(int x, int y) { return x < 0 || x >= n || y < 0 || y >= m; }

bool dfs(int cur) {
	for (auto& next : person[cur]) {
		if (chk[next]) continue;
		chk[next] = true;

		if (from[next] == -1 || dfs(from[next])) {
			from[next] = cur;
			return true;
		}
	}
	return false;
}

int f(int x, int y) { return x * m + y; }

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int t; cin >> t;
	while (t--) {
		memset(from, -1, sizeof(from));
		memset(chk, 0, sizeof(chk));
		for (int i = 0; i < MAX*MAX+5; ++i) person[i].clear();

		cin >> n >> m;
		vector<string> a;
		for (int i = 0; i < n; ++i) {
			string s; cin >> s;
			a.push_back(s);
		}

		for (int i = 0; i < n; ++i) {
			for (int j = 1; j < m; j+=2) {
				if (a[i][j] == 'x') continue;
				for (int d = 0; d < 6; ++d) {
					int nx = i + dx[d], ny = j + dy[d];
					if (OOB(nx, ny)) continue;
					if (a[nx][ny] == 'x') continue;
					person[f(i, j)].push_back(f(nx, ny));
				}
			}
		}

		int ret = 0;
		for (int j = 1; j < m; j+=2) {
			for (int i = 0; i < n; ++i) {
				memset(chk, 0, sizeof(chk));
				if (dfs(f(i, j))) ++ret;
			}
		}

		int B = 0;
		for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) {
			if (a[i][j] == '.') ++B;
		}
		cout << B - ret << '\n';
	}

	return 0;
}