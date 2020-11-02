//16197
#include <bits/stdc++.h>
using namespace std;
#define INF 1000000001
#define MAX 100005
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

struct P {
	int x, y, x2, y2, cnt;
	P() : x(-1), y(-1), x2(-1), y2(-1), cnt(0) {}
	P(int x, int y, int x2, int y2, int cnt) : x(x), y(y), x2(x2), y2(y2), cnt(cnt) {}
};

int n, m;
int dx[] = { -1,1,0,0 }, dy[] = { 0,0,1,-1 };
bool a[21][21];

bool OOB(int x, int y) {
	if (x < 0 || x >= n || y < 0 || y >= m) return true;
	return false;
}

int BFS(P start) {
	queue<P> q;
	q.push(start);
	while (!q.empty()) {
		P cur = q.front(); q.pop();
		if (cur.cnt >= 10) continue;
		for (int i = 0; i < 4; ++i) {
			int nx = cur.x + dx[i], ny = cur.y + dy[i];
			int nx2 = cur.x2 + dx[i], ny2 = cur.y2 + dy[i];
			if (OOB(nx, ny)) {
				if (OOB(nx2, ny2)) continue;
				return cur.cnt + 1;
			}
			else {
				if (OOB(nx2, ny2)) return cur.cnt + 1;
			}

			if (a[nx][ny]) {
				if (a[nx2][ny2]) q.push(P(cur.x, cur.y, cur.x2, cur.y2, cur.cnt + 1));
				else q.push(P(cur.x, cur.y, nx2, ny2, cur.cnt + 1));
			}
			else {
				if(a[nx2][ny2]) q.push(P(nx, ny, cur.x2, cur.y2, cur.cnt + 1));
				else q.push(P(nx, ny, nx2, ny2, cur.cnt + 1));
			}
		}
	}
	return -1;
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n >> m;
	P start;
	for (int i = 0; i < n; ++i) {
		string s; cin >> s;
		for (int j = 0; j < m; ++j) {
			if (s[j] == 'o') {
				if (start.x == -1) {
					start.x = i;
					start.y = j;
				}
				else {
					start.x2 = i;
					start.y2 = j;
				}
			}
			else if (s[j] == '#') a[i][j] = true;
		}
	}
	cout << BFS(start);

	return 0;
}