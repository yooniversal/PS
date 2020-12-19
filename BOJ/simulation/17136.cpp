//17136
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
const int MAX = 10000001, INF = 1000000001, MOD = 1234567;

int dx[] = { 0,-1,0 }, dy[] = { -1,0,1 };
int a[11][11], attachMax[11][11], remain[6], ret = INF, sum;
bool chk[11][11];

bool OOB(int x, int y) { return x < 0 || x >= 10 || y < 0 || y >= 10; }

int maxSize(int x, int y, int cnt) {
	if (OOB(x + cnt, y + cnt)) return cnt;
	bool flag = true;
	for(int r=x; r<=x+cnt; ++r)
		if (a[r][y + cnt] == 0) {
			flag = false;
			break;
		}

	for(int c=y; c<=y+cnt; ++c)
		if(a[x+cnt][y] == 0) {
			flag = false;
			break;
		}

	if (flag) return maxSize(x, y, cnt + 1);
	return cnt;
}

void solve(int x, int y, int cnt, int passed) {
	if (x == 10) {
		if(passed == sum) ret = min(ret, cnt);
		return;
	}
	if (chk[x][y] || a[x][y] == 0) {
		if (y != 9) solve(x, y + 1, cnt, passed);
		else solve(x + 1, 0, cnt, passed);
		return;
	}

	vii xy;
	bool flag = false;
	for (int size = 1; size <= min(5, attachMax[x][y]); ++size) {
		if (remain[size] == 0) continue;
		--remain[size];
		for (int nx = x; nx < x + size; ++nx) {
			if (chk[nx][y + size - 1]) {
				flag = true;
				break;
			}
			chk[nx][y + size - 1] = true;
			xy.push_back({ nx, y + size - 1 });
		}
		for (int ny = y; ny < y + size - 1; ++ny) {
			if (chk[x + size - 1][ny]) {
				flag = true;
				break;
			}
			chk[x + size - 1][ny] = true;
			xy.push_back({ x + size - 1,ny });
		}
		if (flag) {
			++remain[size];
			break;
		}
			
		if (y != 9) solve(x, y + 1, cnt + 1, passed + size*size);
		else solve(x + 1, 0, cnt + 1, passed + size*size);

		++remain[size];
	}

	for (auto& cur : xy) chk[cur.first][cur.second] = false;
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	for (int i = 0; i < 10; ++i)
		for (int j = 0; j < 10; ++j) {
			cin >> a[i][j];
			if (a[i][j]) ++sum;
		}

	for (int i = 0; i < 10; ++i)
		for (int j = 0; j < 10; ++j)
			if (a[i][j] == 1)
				attachMax[i][j] = maxSize(i, j, 0);

	for (int i = 1; i <= 5; ++i) remain[i] = 5;
	solve(0, 0, 0, 0);
	if (ret == INF) cout << -1 << '\n';
	else cout << ret << '\n';

	return 0;
}