//16973
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
const int MAX = 500001, INF = 1000000001, MOD = 1234567;

struct P {
	int x, y, cnt;
};

int dx[] = { 0,0,1,-1 }, dy[] = { 1,-1,0,0 };
int n, m, h, w, sr, sc, fr, fc, a[1001][1001];
bool chk[1001][1001];

bool OOB(int x, int y) { return x <= 0 || x > n || y <= 0 || y > m; }

bool checkSqu(int x, int y) {
	for (int i : {x, x + h - 1} ) for (int j = y; j < y + w; ++j) {
		if (OOB(i, j)) return false;
		if (a[i][j]) return false;
	}
	for (int i = x; i < x + h; ++i) for (int j : {y, y + w - 1}) {
		if (OOB(i, j)) return false;
		if (a[i][j]) return false;
	}
	return true;
}

int BFS() {
	queue<P> q;
	chk[sr][sc] = true;
	q.push({ sr,sc,0 });
	while (!q.empty()) {
		int x = q.front().x, y = q.front().y, cnt = q.front().cnt; q.pop();
		if (x == fr && y == fc) return cnt;
		for (int i = 0; i < 4; ++i) {
			int nx = x + dx[i], ny = y + dy[i];
			if (OOB(nx, ny)) continue;
			if (!checkSqu(nx, ny) || chk[nx][ny]) continue;
			chk[nx][ny] = true;
			q.push({ nx,ny,cnt+1 });
		}
	}
	return -1;
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n >> m;
	for (int i = 1; i <= n; ++i) for (int j = 1; j <= m; ++j) {
		cin >> a[i][j];
	}
	cin >> h >> w >> sr >> sc >> fr >> fc;

	cout << BFS() << '\n';

	return 0;
}