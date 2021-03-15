//17142
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
const int MAX = 100005, INF = 1000000001, MOD = 9901;

int dx[] = { -1,1,0,0 }, dy[] = { 0,0,1,-1 };
int n, m, alive, ret = INF;
int a[51][51];
vii virus, selected;

bool OOB(int x, int y) { return x < 0 || x >= n || y < 0 || y >= n; }

void solve() {
	int Alive = alive;
	vvi d(n, vi(n, INF));
	queue<ii> q;
	for (auto& s : selected) {
		q.push({ s.first, s.second });
		d[s.first][s.second] = 0;
	}

	int TIME = 0;
	bool flag = false;
	while (!q.empty()) {
		int x = q.front().first, y = q.front().second; q.pop();

		if (Alive == 0) {
			flag = true;
			break;
		}

		for (int i = 0; i < 4; ++i) {
			int nx = x + dx[i], ny = y + dy[i];
			if (OOB(nx, ny)) continue;
			if (a[nx][ny] == 1 || d[nx][ny] <= d[x][y]+1) continue;
			if (a[nx][ny] == 0) --Alive;
			d[nx][ny] = d[x][y] + 1;
			TIME = max(TIME, d[nx][ny]);
			q.push({ nx, ny });
		}
	}

	if(flag) ret = min(ret, TIME);
}

void select_virus(int prev, int cnt) {
	if (cnt == m) {
		solve();
		return;
	}

	for (int i = prev+1; i < virus.size(); ++i) {
		selected.emplace_back(make_pair(virus[i].first, virus[i].second));
		select_virus(i, cnt + 1);
		selected.pop_back();
	}
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n >> m;
	for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) {
		cin >> a[i][j];
		if (a[i][j] == 2) virus.emplace_back(make_pair(i, j));
		if (a[i][j] == 0) ++alive;
	}

	select_virus(-1, 0);
	
	if (ret == INF) cout << -1 << '\n';
	else cout << ret << '\n';

	return 0;
}