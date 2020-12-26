//16932
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
const int MAX = 500001, INF = 1000000001, MOD = 1234567;

struct P {
	int x, y;
};

int dx[] = { -1,1,0,0 }, dy[] = { 0,0,1,-1 };
int n, m, a[1001][1001], num[1001][1001], S[1000001];
bool chk[1001][1001], counted[1000001];

bool OOB(int x, int y) { return x < 0 || x >= n || y < 0 || y >= m; }

int BFS() {
	int ret = 0;
	queue<ii> q;
	for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) {
		if (a[i][j] == 0) q.push({ i,j });
	}
	while (!q.empty()) {
		int x = q.front().first, y = q.front().second; q.pop();
		
		int tmp = 0;
		vi used;
		for (int i = 0; i < 4; ++i) {
			int nx = x + dx[i], ny = y + dy[i];
			if (OOB(nx, ny)) continue;
			if (!a[nx][ny] || counted[num[nx][ny]]) continue;
			counted[num[nx][ny]] = true;
			used.emplace_back(num[nx][ny]);
			tmp += S[num[nx][ny]];
		}
		for (int& n : used) counted[n] = false;
		ret = max(ret, tmp+1);
	}
	return ret;
}

void DFS(int x, int y, int cnt) {
	chk[x][y] = true;
	num[x][y] = cnt;
	++S[cnt];
	for (int i = 0; i < 4; ++i) {
		int nx = x + dx[i], ny = y + dy[i];
		if (OOB(nx, ny)) continue;
		if (!a[nx][ny] || chk[nx][ny]) continue;
		DFS(nx, ny, cnt);
	}
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n >> m;
	for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) {
		cin >> a[i][j];
	}

	int cnt = 0;
	for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) {
		if (chk[i][j] || !a[i][j]) continue;
		DFS(i, j, ++cnt);
	}

	cout << BFS() << '\n';

	return 0;
}