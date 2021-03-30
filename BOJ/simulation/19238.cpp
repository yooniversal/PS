//19238
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
const int MAX = 100005, INF = 1000000001, MOD = 9901;

struct P {
	int x, y, fx, fy;
};

struct Q {
	int x, y, cnt;
};

int dx[] = { -1,1,0,0 }, dy[] = { 0,0,1,-1 };
int n, m, f, MAP[21][21], cx, cy, st[21][21];
P pers[401];

bool OOB(int x, int y) { return x < 0 || x >= n || y < 0 || y >= n; }

Q BFS() {
	bool chk[21][21] = { 0, };
	queue<Q> q;
	q.push({ cx, cy, 0 });
	chk[cx][cy] = true;
	int base = -1, rx = -1, ry = -1;
	while (!q.empty()) {
		int x = q.front().x, y = q.front().y, cnt = q.front().cnt; q.pop();
		if (st[x][y] != -1) {
			if (base == -1) {
				base = cnt;
				rx = x, ry = y;
			}
			else if (base == cnt) {
				if (x < rx) rx = x, ry = y;
				else if (x == rx && y < ry) rx = x, ry = y;
			}
			else
				break;
			continue;
		}
		if (base != -1) continue;

		for (int i = 0; i < 4; ++i) {
			int nx = x + dx[i], ny = y + dy[i];
			if (OOB(nx, ny) || MAP[nx][ny] || chk[nx][ny]) continue;
			chk[nx][ny] = true;
			q.push({ nx, ny, cnt + 1 });
		}
	}
	return { rx,ry,base };
}

int BFS_to_goal() {
	ii goal = { pers[st[cx][cy]].fx, pers[st[cx][cy]].fy };
	bool chk[21][21] = { 0, };
	queue<Q> q;
	q.push({ cx,cy,0 });
	while (!q.empty()) {
		int x = q.front().x, y = q.front().y, cnt = q.front().cnt; q.pop();
		if (goal.first == x && goal.second == y) {
			st[cx][cy] = -1;
			cx = x, cy = y;
			return cnt;
		}
		for (int i = 0; i < 4; ++i) {
			int nx = x + dx[i], ny = y + dy[i];
			if (OOB(nx, ny) || MAP[nx][ny] || chk[nx][ny]) continue;
			chk[nx][ny] = true;
			q.push({ nx, ny, cnt + 1 });
		}
	}
	return -1;
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	memset(st, -1, sizeof(st));
	cin >> n >> m >> f;
	for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) {
		cin >> MAP[i][j];
	}
	cin >> cx >> cy;
	--cx, --cy;
	for (int i = 0; i < m; ++i) {
		cin >> pers[i].x >> pers[i].y >> pers[i].fx >> pers[i].fy;
		--pers[i].x, --pers[i].y;
		--pers[i].fx, --pers[i].fy;
		st[pers[i].x][pers[i].y] = i;
	}

	int cnt = 0;
	while (cnt != m) {
		auto tmp = BFS();
		if (tmp.cnt == -1 || tmp.cnt > f) {
			cout << -1 << '\n';
			return 0;
		}
		f -= tmp.cnt;
		cx = tmp.x, cy = tmp.y;
		int tmp2 = BFS_to_goal();
		if (tmp2 == -1 || tmp2 > f) {
			cout << -1 << '\n';
			return 0;
		}
		f -= tmp2;
		f += tmp2 * 2;
		++cnt;
	}
	cout << f << '\n';

	return 0;
}