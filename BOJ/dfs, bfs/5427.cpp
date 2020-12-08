//5427
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
const int MAX = 1001, INF = 1000000001, MOD = 1234567;

struct state {
	int x, y;
	bool live;
	state() : x(-1), y(-1), live(false) {}
	state(int a, int b, bool c) : x(a), y(b), live(c) {}
};

int board[MAX][MAX];
bool chk[MAX][MAX];
int dx[] = { -1,1,0,0 }, dy[] = { 0,0,1,-1 };
int n, m, ret;
state J;
queue<state> F;

bool bfs() {
	queue<state> q;
	chk[J.x][J.y] = true;
	while (!F.empty()) {
		state curF = F.front(); F.pop();
		chk[curF.x][curF.y] = true;
		q.push(curF);
	}
	q.push(J);
	while (!q.empty()) {
		int curx = q.front().x, cury = q.front().y;
		bool live = q.front().live;
		q.pop();

		if (live)
			if (curx == n - 1 || curx == 0 || cury == m - 1 || cury == 0) {
				ret = board[curx][cury];
				return true;
			}

		for (int i = 0; i < 4; i++) {
			int nx = curx + dx[i], ny = cury + dy[i];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m || board[nx][ny] == 0) continue;
			if (chk[nx][ny]) continue;
			chk[nx][ny] = true;
			if (live) board[nx][ny] += board[curx][cury];
			q.push(state(nx, ny, live));
		}
	}
	return false;
}

void init() {
	for (int i = 0; i < MAX; ++i) for (int j = 0; j < MAX; ++j) {
		chk[i][j] = 0;
		board[i][j] = 1;
	}
	while (!F.empty()) F.pop();
	J.live = false;
	J.x = J.y = -1;
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int t; cin >> t;
	while (t--) {
		init();

		cin >> m >> n;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				char a; cin >> a;
				if (a == '#') board[i][j] = 0;
				else if (a == '.') board[i][j] = 1;
				else if (a == '@') J = state(i, j, true);
				else if (a == '*') F.push(state(i, j, false));
			}
		}

		board[J.x][J.y] = 1;
		if (bfs()) cout << ret << '\n';
		else cout << "IMPOSSIBLE\n";
	}

	return 0;
}