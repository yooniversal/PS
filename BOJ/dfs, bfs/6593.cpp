//6593
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
const int MAX = 100005, INF = 1000000001, MOD = 9901;

struct S {
	int x, y, z, cnt;
};

int L, R, C;
int dx[] = { -1,1,0,0,0,0 }, dy[] = { 0,0,1,-1,0,0 }, dz[] = { 0,0,0,0,1,-1 };
char a[31][31][31];
bool chk[31][31][31];

bool OOB(int x, int y, int z) {
	return x < 0 || x >= L || y < 0 || y >= R || z < 0 || z >= C;
}

int BFS(int sx, int sy, int sz) {
	
	S start = { sx, sy, sz, 0 };
	queue<S> q;
	q.push(start);
	chk[sx][sy][sz] = true;
	while (!q.empty()) {
		S cur = q.front(); q.pop();

		if (a[cur.x][cur.y][cur.z] == 'E') {
			return cur.cnt;
		}

		if (cur.cnt > 29791) {
			printf("*%d\n", cur.cnt);
			break;
		}

		for (int i = 0; i < 6; ++i) {
			int nx = cur.x + dx[i], ny = cur.y + dy[i], nz = cur.z + dz[i];
			if (OOB(nx, ny, nz) || chk[nx][ny][nz]) continue;
			if (a[nx][ny][nz] == '#') continue;
			chk[nx][ny][nz] = true;
			q.push({ nx, ny, nz, cur.cnt + 1 });
		}
	}

	return -1;
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	while (1) {
		cin >> L >> R >> C;

		if (L == 0 && R == 0 && C == 0) break;
		
		int sx = -1, sy = -1, sz = -1;
		for (int i = 0; i < L; ++i) {
			for (int j = 0; j < R; ++j) {
				for (int k = 0; k < C; ++k) {
					cin >> a[i][j][k];
					if (a[i][j][k] == 'S') {
						sx = i, sy = j, sz = k;
					}
				}
			}
		}

		memset(chk, false, sizeof(chk));

		int ret = BFS(sx, sy, sz);
		if (ret == -1) {
			cout << "Trapped!\n";
		}
		else {
			cout << "Escaped in "<< ret <<" minute(s).\n";
		}

	}

	return 0;
}