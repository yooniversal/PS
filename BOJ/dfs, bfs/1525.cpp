//1525
//non-complete
#include <bits/stdc++.h>
using namespace std;
#define INF 1000000000
#define MAX 4000005
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

struct M {
	vvi v;
	int x, y, cnt;
	M(vvi a, int b, int c, int d) : v(a), x(b), y(c), cnt(d) {}
};

int dx[] = { -1,1,0,0 }, dy[] = { 0,0,1,-1 };
int e[3][3] = { {1, 2, 3},
				{4,5,6},
				{7,8,0} };

bool fin(M& a) {
	if (!(a.x == 2 && a.y == 2)) return false;
	for (int i = 0; i < 3; ++i)
		for (int j = 0; j < 3; ++j)
			if (a.v[i][j] != e[i][j]) return false;
	return true;
}

bool OOB(int x, int y) {
	if (x < 0 || x >= 3 || y < 0 || y >= 3) return true;
	return false;
}

vvi swap(vvi v, const ii& a, const ii& b) {
	int tmp = v[a.first][a.second];
	v[a.first][a.second] = v[b.first][b.second];
	v[b.first][b.second] = tmp;
	return v;
}

int bfs(vvi& v, int a, int b) {
	queue<M> q;
	q.push(M(v, a, b, 0));
	while (!q.empty()) {
		M cur = q.front(); q.pop();
		if (fin(cur)) return cur.cnt;
		if (cur.cnt > 20) return -1;
		/*for (int i = 0; i < 3; ++i) {
			for (int j = 0; j < 3; ++j)
				cout << cur.v[i][j] << " ";
			cout << '\n';
		}
		cout << '\n';*/

		for (int i = 0; i < 4; ++i) {
			int nx = cur.x + dx[i], ny = cur.y + dy[i];
			if (OOB(nx, ny)) continue;
			ii cxy = { cur.x, cur.y }, nxy = { nx,ny };
			q.push(M(swap(cur.v, cxy, nxy), nx, ny, cur.cnt + 1));
		}
	}
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	vvi v(3, vi(3));
	int a, b;
	for (int i = 0; i < 3; ++i)
		for (int j = 0; j < 3; ++j) {
			cin >> v[i][j];
			if (v[i][j] == 0) {
				a = i;
				b = j;
			}
		}

	cout << bfs(v, a, b);

	return 0;
}