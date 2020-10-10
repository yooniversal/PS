//4991
#include <bits/stdc++.h>
using namespace std;
#define INF 1000000007
#define MAX 4000005
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

struct P {
	int x, y, cbit;
};

int a[21][21];
int h, w;
int dx[] = { -1,1,0,0 }, dy[] = { 0,0,1,-1 };
int chk[1<<10][21][21];

bool OOB(int x, int y) {
	if (x < 0 || x >= h || y < 0 || y >= w) return true;
	return false;
}

void bfs(ii start, int dust) {
	memset(chk, 0, sizeof(chk));
	queue<P> q;
	q.push({ start.first, start.second, 0 });
	while (!q.empty()) {
		int x = q.front().x, y = q.front().y;
		int cbit = q.front().cbit; q.pop();
		if (cbit == (1 << dust) - 1) {
			cout << chk[cbit][x][y] << '\n';
			return;
		}
		for (int i = 0; i < 4; ++i) {
			int nx = x + dx[i], ny = y + dy[i];
			if (OOB(nx, ny)) continue;
			if (a[nx][ny] == -1) continue;
			if (chk[cbit][nx][ny]) continue;
			if (a[nx][ny] >= 0) {
				int nbit = cbit | (1<<a[nx][ny]);
				chk[nbit][nx][ny] = chk[cbit][x][y]+1;
				q.push({ nx, ny, nbit });
			}
			else {
				chk[cbit][nx][ny] = chk[cbit][x][y]+1;
				q.push({ nx, ny, cbit });
			}
		}
	}
	cout << -1 << '\n';
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	while (1) {
		memset(a, 0, sizeof(a));

		cin >> w >> h;
		ii start;
		int dust = 0, dnum = 0;
		if (w == 0 && h == 0) break;
		for (int i = 0; i < h; ++i) {
			string s; cin >> s;
			for (int j = 0; j < w; ++j) {
				if (s[j] == 'x') a[i][j] = -1;
				else if (s[j] == 'o') {
					a[i][j] = -2;
					start.first = i;
					start.second = j;
				}
				else if (s[j] == '*') {
					a[i][j] = dnum++;
					++dust;
				}
				else a[i][j] = -2;
			}
		}
		bfs(start, dust);
	}

	return 0;
}