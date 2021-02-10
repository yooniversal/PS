//16954
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
const int MAX = 10001, INF = 1000000001, MOD = 9901;

int dx[] = { -1,-1,-1,0,0,0,1,1,1 }, dy[] = { -1,0,1,-1,0,1,-1,0,1 };
char a[8][8];
bool chk[8][8];

bool OOB(int x, int y) { return x >= 8 || y < 0 || y >= 8; }
bool FIN(int x, int y) { return (x == 0 && y == 7) || x < 0; }

void BFS() {
	queue<ii> q;
	q.push({ 7,0 });
	chk[7][0] = true;
	while (!q.empty()) {
		int x = q.front().first, y = q.front().second; q.pop();

		for (int i = 0; i < 9; ++i) {
			int nx = x + dx[i], ny = y + dy[i];
			if (OOB(nx, ny) || OOB(nx - 1, ny)) continue;
			if (nx < 0) {
				cout << 1 << '\n';
				exit(0);
			}
			if (a[nx][ny] == '#' || a[nx - 1][ny] == '#' || chk[nx - 1][ny]) continue;
			if (nx - 1 <= 0) {
				cout << 1 << '\n';
				exit(0);
			}
			chk[nx - 1][ny] = true;
			q.push({ nx - 1, ny });
		}
	}
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	for (int i = 0; i < 8; ++i) for (int j = 0; j < 8; ++j) cin >> a[i][j];

	BFS();
	cout << 0 << '\n';

	return 0;
}