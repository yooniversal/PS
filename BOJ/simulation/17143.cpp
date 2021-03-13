//17143
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
const int MAX = 100005, INF = 1000000001, MOD = 9901;

struct P {
	int x, y, s, d, z;
};

int r, c, m;
int dx[] = { -1,0,1,0 }, dy[] = { 0,-1,0,1 };
int a[101][101];
P fish[10001];
bool dead[10001];

bool OOB(int x, int y) { return x < 0 || x >= r || y < 0 || y >= c; }

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> r >> c >> m;
	for (int i = 0; i < m; ++i) {
		int x, y, s, d, z; cin >> x >> y >> s >> d >> z;
		if (d == 1) d = 0;
		else if (d == 2) d = 2;
		else if (d == 3) d = 3;
		else d = 1;
		fish[i] = { --x,--y,s,d,z };
	}

	int ret = 0;
	for (int cur = 0; cur < c; ++cur) {
		// 초기화
		for (int i = 0; i < r; ++i) for (int j = 0; j < c; ++j) a[i][j] = -1;

		// 물고기 잡기
		int target = -1;
		for (int i = 0; i < m; ++i) {
			if (dead[i] || fish[i].y != cur) continue;
			if (target == -1 || fish[target].x > fish[i].x) target = i;
		}
		if(target != -1) dead[target] = true;
		ret += fish[target].z;

		// 물고기 이동
		for (int i = 0; i < m; ++i) {
			if (dead[i]) continue;
			int ns = fish[i].d%2==0 ? fish[i].s%(2*r-2) : fish[i].s%(2*c-2);
			int nx = fish[i].x + dx[fish[i].d] * ns, ny = fish[i].y + dy[fish[i].d] * ns, nd = fish[i].d;
			fish[i].x = nx;
			fish[i].y = ny;
			while (OOB(nx, ny)) {
				if (nx < 0 || nx >= r) {
					if (nx < 0) ns = -nx, nx = 0;
					else ns = nx - r + 1, nx = r-1;
				}
				else {
					if (ny < 0) ns = -ny, ny = 0;
					else ns = ny - c + 1, ny = c-1;
				}
				
				fish[i].d = nd = (nd + 2) % 4;
				fish[i].x = nx = nx + dx[nd] * ns;
				fish[i].y = ny = ny + dy[nd] * ns;
			}
			
			// 물고기가 있다면
			if (a[nx][ny] != -1) {
				if (fish[a[nx][ny]].z < fish[i].z) {
					dead[a[nx][ny]] = true;
					a[nx][ny] = i;
				}
				else {
					dead[i] = true;
				}
			}
			// 없다면
			else {
				a[nx][ny] = i;
			}
		}
	}

	cout << ret << '\n';

	return 0;
}