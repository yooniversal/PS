//17837
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
const int MAX = 100005, INF = 1000000001, MOD = 9901;

struct S {
	int x, y, d;
};

int dx[] = { -1,0,1,0 }, dy[] = { 0,-1,0,1 };
int n, k, a[13][13], ret;
stack<int> b[13][13];
S place[11];

bool OOB(int x, int y) { return x < 0 || x >= n || y < 0 || y >= n; }

void solve() {
	queue<int> q;
	for (int i = 1; i <= k; ++i) q.push(i);
	while (1) {
		int cur = q.front(); q.pop();
		int x = place[cur].x, y = place[cur].y, d = place[cur].d;
		if (cur == 1) ++ret;
		if (ret > 1000) break;

		int nx = x + dx[d], ny = y + dy[d];
		if (OOB(nx, ny) || a[nx][ny] == 2) {
			d = (d + 2) % 4;
			place[cur].d = d;
			int nnx = x + dx[d], nny = y + dy[d];
			if (OOB(nnx, nny) || a[nnx][nny] == 2) {
				q.push(cur);
				continue;
			}
			if (a[nnx][nny] == 0) {
				place[cur].x = nnx;
				place[cur].y = nny;
				stack<int> ts;
				while (b[x][y].top() != cur) {
					place[b[x][y].top()].x = nnx;
					place[b[x][y].top()].y = nny;
					ts.push(b[x][y].top()); b[x][y].pop();
				}
				ts.push(b[x][y].top()); b[x][y].pop();
				while (!ts.empty()) {
					b[nnx][nny].push(ts.top()); ts.pop();
				}
				if (b[nnx][nny].size() >= 4) {
					cout << ret << '\n';
					return;
				}
			}
			else {
				place[cur].x = nnx;
				place[cur].y = nny;
				queue<int> tq;
				while (b[x][y].top() != cur) {
					place[b[x][y].top()].x = nnx;
					place[b[x][y].top()].y = nny;
					tq.push(b[x][y].top()); b[x][y].pop();
				}
				tq.push(b[x][y].top()); b[x][y].pop();
				while (!tq.empty()) {
					b[nnx][nny].push(tq.front()); tq.pop();
				}

				if (b[nnx][nny].size() >= 4) {
					cout << ret << '\n';
					return;
				}
			}
		}
		else {
			if (a[nx][ny] == 0) {
				place[cur].x = nx;
				place[cur].y = ny;
				stack<int> ts;
				while (b[x][y].top() != cur) {
					place[b[x][y].top()].x = nx;
					place[b[x][y].top()].y = ny;
					ts.push(b[x][y].top()); b[x][y].pop();
				}
				ts.push(b[x][y].top()); b[x][y].pop();
				while (!ts.empty()) {
					b[nx][ny].push(ts.top()); ts.pop();
				}

				if (b[nx][ny].size() >= 4) {
					cout << ret << '\n';
					return;
				}
			}
			else {
				place[cur].x = nx;
				place[cur].y = ny;
				queue<int> tq;
				while (b[x][y].top() != cur) {
					place[b[x][y].top()].x = nx;
					place[b[x][y].top()].y = ny;
					tq.push(b[x][y].top()); b[x][y].pop();
				}
				tq.push(b[x][y].top()); b[x][y].pop();
				while (!tq.empty()) {
					b[nx][ny].push(tq.front()); tq.pop();
				}

				if (b[nx][ny].size() >= 4) {
					cout << ret << '\n';
					return;
				}
			}
		}
		q.push(cur);
	}

	cout << -1 << '\n';
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n >> k;
	for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) cin >> a[i][j];
	for (int i = 1; i <= k; ++i) {
		int x, y, d; cin >> x >> y >> d;
		if (d == 3) d = 0;
		else if (d == 4) d = 2;
		else if (d == 1) d = 3;
		else d = 1;

		--x, --y;
		place[i] = { x,y,d };
		b[x][y].push(i);
	}
	
	solve();

	return 0;
}