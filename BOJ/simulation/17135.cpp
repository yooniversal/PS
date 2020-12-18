//17135
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
const int MAX = 10000001, INF = 1000000001, MOD = 1234567;

struct P {
	int x, y, dcnt;
};

int dx[] = { 0,-1,0 }, dy[] = { -1,0,1 };
int a[16][16], chk[16][16], killed[16][16];
int n, m, d, ret, cnt;

bool OOB(int x, int y) { return x < 0 || x >= n || y < 0 || y >= m; }

//가능한 거리만큼 탐색
//만약 적을 제거한다면 종료
void Search(int x, int y, int round) {
	queue<P> q;
	chk[x][y] = d - 1;
	q.push({ x, y, d-1 });
	while (!q.empty()) {
		int x = q.front().x, y = q.front().y, dcnt = q.front().dcnt; q.pop();
		if (dcnt < 0) break;
		if (a[x][y] == 1 && (killed[x][y] == 0 || killed[x][y] == round)) {
			if (killed[x][y] == 0) {
				killed[x][y] = round;
				++cnt;
			}
			break;
		}
		for (int i = 0; i < 3; ++i) {
			int nx = x + dx[i], ny = y + dy[i];
			if (OOB(nx, ny)) continue;
			if (chk[nx][ny] > dcnt - 1 && a[nx][ny] == 0) continue;
			chk[nx][ny] = dcnt - 1;
			q.push({ nx,ny,dcnt-1 });
		}
	}
}

void solve(const vi& archers) {
	int round = 0;
	for (int next_row = n - 1; next_row >= 0; --next_row) {
		memset(chk, -1, sizeof(chk));
		++round;
		for (int cur_col = 0; cur_col < m; ++cur_col)
			if (archers[cur_col] == 1)
				Search(next_row, cur_col, round);
	}
	ret = max(ret, cnt);
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n >> m >> d;
	for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) {
		cin >> a[i][j];
	}
	
	vi archers(m, 0);
	for (int i = m - 1; i >= m - 3; --i) archers[i] = 1;

	do {
		memset(killed, 0, sizeof(killed));
		cnt = 0;
		solve(archers);
	} while (next_permutation(archers.begin(), archers.end()));
	cout << ret << '\n';

	return 0;
}