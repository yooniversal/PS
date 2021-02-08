//2146
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
const int MAX = 1000001, INF = 1000000001, MOD = 9901;

int dx[] = { -1,1,0,0 }, dy[] = { 0,0,1,-1 };
int n, cnt;
int a[101][101];
bool chk[101][101];
vii island[10001];

bool OOB(int x, int y) { return x < 0 || x >= n || y < 0 || y >= n; }

void DFS(int x, int y) {
	for (int i = 0; i < 4; ++i) {
		int nx = x + dx[i], ny = y + dy[i];
		if (OOB(nx, ny)) continue;
		if (chk[nx][ny] || a[nx][ny] == 0) continue;
		chk[nx][ny] = true;
		island[cnt].push_back({ nx,ny });
		DFS(nx, ny);
	}
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n;
	ii start = { -1, -1 };
	for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) {
		cin >> a[i][j];
		if (a[i][j] == 1 && start.first == -1) {
			start.first = i;
			start.second = j;
		}
	}

	for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) {
		if (chk[i][j] || a[i][j] == 0) continue;
		chk[i][j] = true;
		island[cnt].push_back({ i,j });
		DFS(i, j);
		++cnt;
	}

	int ret = INF;
	for (int i = 0; i < cnt; ++i) {
		for (int j = 0; j < cnt; ++j) {
			if (i == j) continue;
			for (auto& C : island[i]) {
				for (auto& N : island[j]) {
					ret = min(ret, abs(C.first - N.first) + abs(C.second - N.second) - 1);
				}
			}
		}
	}
	cout << ret << '\n';

	return 0;
}