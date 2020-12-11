//2174
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
const int MAX = 5005, INF = 1000000001, MOD = 1234567;

struct P {
	int x, y, d;
	P(int a, int b, int c) {
		x = a;
		y = b;
		d = c;
	}
	P() {
		P(-1, -1, -1);
	}
};

int dx[] = { -1,0,1,0 }, dy[] = { 0,-1,0,1 };
int n, m;
P robot[101];
int MAP[101][101];

bool OOB(int x, int y) { return x < 1 || x > n || y < 1 || y > m; }

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> m >> n;
	int a, b; cin >> a >> b;
	for (int i = 1; i <= a; ++i) {
		int x, y; char dir; cin >> y >> x >> dir;
		if (dir == 'S') robot[i] = P(x,y,0);
		else if (dir == 'W') robot[i] = P(x, y, 1);
		else if (dir == 'N') robot[i] = P(x, y, 2);
		else robot[i] = P(x, y, 3);
		MAP[x][y] = i;
	}
	while (b--) {
		int N, time; char q; cin >> N >> q >> time;
		if (q == 'L') {
			time %= 4;
			for (int i = 0; i < time; ++i) {
				if (robot[N].d == 0) robot[N].d = 3;
				else --robot[N].d;
			}
		}
		else if (q == 'R') {
			time %= 4;
			robot[N].d = (robot[N].d + time) % 4;
		}
		else {
			for (int i = 0; i < time; ++i) {
				MAP[robot[N].x][robot[N].y] = 0;
				int nx = robot[N].x + dx[robot[N].d];
					cout << "Robot " << N << " crashes into the wall\n";
					return 0;
				}
				if (MAP[nx][ny]) {
					cout << "Robot " << N << " crashes into robot " << MAP[nx][ny] << '\n';
					return 0;
				}
				MAP[nx][ny] = N;
				robot[N].x = nx, robot[N].y = ny;
			}
		}
	}
	cout << "OK\n";

	return 0;
}