//16920
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
const int MAX = 500001, INF = 1000000001, MOD = 1234567;

struct P {
	int x, y;
};

int dx[] = { -1,1,0,0 }, dy[] = { 0,0,1,-1 };
int n, m, p, s[10], a[1001][1001], chk[1001][1001];
vector<P> land[10];
queue<P> q[10];

bool OOB(int x, int y) { return x < 0 || x >= n || y < 0 || y >= m; }

void BFS() {
	for (int i = 1; i <= p; ++i)
		for (auto& xy : land[i]) {
			q[a[xy.x][xy.y]].push({ xy.x, xy.y });
			chk[xy.x][xy.y] = s[a[xy.x][xy.y]];
		}

	int stop = 0;
	for (int now = 1; stop != p; ++now) {
		if (now == p+1) now = 1;
		
		for (int rem = 0; rem < s[now]; ++rem) {
			int size = q[now].size();
			while (size--) {
				int x = q[now].front().x, y = q[now].front().y; q[now].pop();
				for (int i = 0; i < 4; ++i) {
					int nx = x + dx[i], ny = y + dy[i];
					if (OOB(nx, ny)) continue;
					if (a[nx][ny] != 0) continue;
					a[nx][ny] = now;
					q[now].push({ nx,ny });
				}
			}
			if (q[now].size() == 0) break;
		}

		if (q[now].size() == 0) ++stop;
		else stop = 0;
	}
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n >> m >> p;
	for (int i = 1; i <= p; ++i) cin >> s[i];
	for (int i = 0; i < n; ++i) {
		string str; cin >> str;
		for (int j = 0; j < m; ++j) {
			if (str[j] == '.') a[i][j] = 0;
			else if (str[j] == '#') a[i][j] = -1;
			else {
				int now = str[j] - '0';
				a[i][j] = now;
				land[now].push_back({ i,j });
			}
		}
	}

	BFS();

	int ret[10] = { 0, };
	for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) {
		if (a[i][j] == 0 || a[i][j] == -1) continue;
		++ret[a[i][j]];
	}

	for (int i = 1; i <= p; ++i) cout << ret[i] << ' ';
	cout << '\n';

	return 0;
}