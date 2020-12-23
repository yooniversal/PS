//16948
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
const int MAX = 10000001, INF = 1000000001, MOD = 1234567;

struct P {
	int x, y, cnt;
};

int dx[] = { -2,-2,0,0,2,2 }, dy[] = { -1,1,-2,2,-1,1 };
int n, r1, c1, r2, c2;
bool chk[201][201];

bool OOB(int x, int y) { return x < 0 || x >= n || y < 0 || y >= n; }

int BFS() {
	queue<P> q;
	chk[r1][c1] = true;
	q.push({ r1,c1,0 });
	while (!q.empty()) {
		int x = q.front().x, y = q.front().y, cnt = q.front().cnt; q.pop();
		if (x == r2 && y == c2) return cnt;
		for (int i = 0; i < 6; ++i) {
			int nx = x + dx[i], ny = y + dy[i];
			if (OOB(nx, ny)) continue;
			if (chk[nx][ny]) continue;
			chk[nx][ny] = true;
			q.push({ nx,ny,cnt + 1 });
		}
	}
	return -1;
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n >> r1 >> c1 >> r2 >> c2;
	cout << BFS() << '\n';

	return 0;
}