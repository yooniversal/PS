//16985
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
const int MAX = 501, INF = 1000000001, MOD = 1000000007;

struct P {
	int z, x, y;
};

vector<vector<vvi>> maze; //Ãþ, µ¹¸° È½¼ö, Çà, ¿­
int dz[] = { -1,1,0,0,0,0 }, dx[] = { 0,0,-1,1,0,0 }, dy[] = { 0,0,0,0,1,-1 };
int sx[] = { 0,0,4,4 }, sy[] = { 0,4,0,4 };
int dist[5][5][5];

bool OOB(int z, int x, int y) { return z < 0 || z >= 5 || x < 0 || x >= 5 || y < 0 || y >= 5; }

void BFS(const vector<vvi>& a, int x, int y) {
	memset(dist, 0, sizeof(dist));
	queue<P> q;
	q.push({ 0, x, y });
	dist[0][x][y] = 0;
	while (!q.empty()) {
		int z = q.front().z, x = q.front().x, y = q.front().y; q.pop();
		for (int i = 0; i < 6; ++i) {
			int nz = z + dz[i], nx = x + dx[i], ny = y + dy[i];
			if (OOB(nz, nx, ny)) continue;
			if (a[nz][nx][ny] == 0 || dist[nz][nx][ny]) continue;
			dist[nz][nx][ny] = dist[z][x][y] + 1;
			q.push({ nz,nx,ny });
		}
	}
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	maze.resize(5, vector<vvi>(5, vvi(5, vi(5))));
	for (int block = 0; block < 5; ++block) {
		for (int i = 0; i < 5; ++i) {
			for (int j = 0; j < 5; ++j) {
				cin >> maze[block][0][i][j];
				maze[block][1][4 - j][i] = maze[block][0][i][j];
				maze[block][2][4 - i][4 - j] = maze[block][0][i][j];
				maze[block][3][j][4 - i] = maze[block][0][i][j];
			}
		}
	}

	int ret = INF;
	vi floor = { 0,1,2,3,4 };
	do {
		for (int r1 = 0; r1 < 4; ++r1) {
			for (int r2 = 0; r2 < 4; ++r2) {
				for (int r3 = 0; r3 < 4; ++r3) {
					for (int r4 = 0; r4 < 4; ++r4) {
						for (int r5 = 0; r5 < 4; ++r5) {
							vector<vvi> a(5);
							a[0] = maze[floor[0]][r1];
							a[1] = maze[floor[1]][r2];
							a[2] = maze[floor[2]][r3];
							a[3] = maze[floor[3]][r4];
							a[4] = maze[floor[4]][r5];

							for (int i = 0; i < 4; ++i) {
								int x = sx[i], y = sy[i];
								if (a[0][x][y] == 0) continue;
								BFS(a, x, y);
									
								//´ä °»½Å
								int ex = x == 0 ? 4 : 0, ey = y == 0 ? 4 : 0;
								ret = min(ret, dist[4][ex][ey] == 0 ? INF : dist[4][ex][ey]);
							}
						}
					}
				}
			}
		}
	} while (next_permutation(floor.begin(), floor.end()));

	if (ret == INF) cout << -1 << '\n';
	else cout << ret << '\n';

	return 0;
}