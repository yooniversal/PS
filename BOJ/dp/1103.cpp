//1103
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

int n, m;
int MAP[51][51];
int cache[51][51];
bool cycle[51][51];
int dx[] = { -1,1,0,0 }, dy[] = { 0,0,1,-1 };
vii route;

bool OOB(int x, int y) {
	if (x < 0 || x >= n || y < 0 || y >= m) return true;
	return false;
}

int f(int x, int y) {
	if (cycle[x][y]) return INF;
	int& ret = cache[x][y];
	if (ret != -1) {
		bool flag = false;
		int SIZE = route.size();
		for (int i = 0; i < SIZE - 1; ++i) {
			if (route[i].first == x && route[i].second == y) {
				flag = true; break;
			}
		}
		if (flag) {
			for (int i = 0; i < SIZE - 1; ++i)
				cycle[route[i].first][route[i].second] = true;
			return ret = INF;
		}
		return ret;
	}
	ret = 0;
	for (int i = 0; i < 4; ++i) {
		int nx = x + dx[i]*MAP[x][y], ny = y + dy[i]*MAP[x][y];
		if (OOB(nx, ny)) continue;
		if (MAP[nx][ny] == 0) continue;
		route.push_back({ nx, ny });
		ret = max(ret, min(INF, f(nx, ny) + 1));
		route.pop_back();
	}
	return ret;
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	memset(cache, -1, sizeof(cache));
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		string s; cin >> s;
		for (int j = 0; j < m; ++j) {
			if (s[j] != 'H') MAP[i][j] = s[j] - '0';
			else MAP[i][j] = 0;
		}
	}
	route.push_back({ 0,0 });
	if (f(0, 0) < INF) cout << f(0, 0)+1;
	else cout << -1;

	return 0;
}