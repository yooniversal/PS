//2186
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
const int MAX = 100001, INF = 1000000001;

int dx[] = { -1,1,0,0 }, dy[] = { 0,0,1,-1 };
int n, m, k;
int cache[101][101][81];
vector<string> MAP;
string s;

bool OOB(int x, int y) { return x < 0 || x >= n || y < 0 || y >= m; }

int f(int x, int y, int now) {
	if (now == s.size()) return 1;
	int& ret = cache[x][y][now];
	if (ret != -1) return ret;
	ret = 0;
	
	for (int i = 0; i < 4; ++i) {
		for (int far = 1; far <= k; ++far) {
			int nx = x + dx[i]*far, ny = y + dy[i]*far;
			if (OOB(nx, ny)) continue;
			if (MAP[nx][ny] != s[now]) continue;
			ret += f(nx, ny, now + 1);
		}
	}

	return ret;
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	memset(cache, -1, sizeof(cache));
	cin >> n >> m >> k;
	for (int i = 0; i < n; ++i) {
		string tmp; cin >> tmp;
		MAP.push_back(tmp);
	}
	cin >> s;
	
	int ret = 0;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			if (MAP[i][j] == s[0])
				ret += f(i, j, 1);
	cout << ret << '\n';

	return 0;
}