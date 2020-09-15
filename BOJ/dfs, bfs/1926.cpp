//1926

#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <cmath>
#include <algorithm>
#include <map>
using namespace std;
#define INF 1000000001
#define MAX 501
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

int board[MAX][MAX];
bool chk[MAX][MAX];
int dx[] = { -1,1,0,0 }, dy[] = { 0,0,1,-1 };
int ret;
int n, m;

void bfs(int x, int y) {
	int cnt = 0;
	queue<ii> q;
	chk[x][y] = true;
	q.push({ x, y });
	while (!q.empty()) {
		int curx = q.front().first;
		int cury = q.front().second;
		cnt++;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = curx + dx[i], ny = cury + dy[i];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m || board[nx][ny] == 0) continue;
			if (chk[nx][ny]) continue;
			chk[nx][ny] = true;
			q.push({ nx, ny });
		}
	}
	ret = max(ret, cnt);
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
		}
	}

	int pic = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (chk[i][j] || board[i][j] == 0) continue;
			pic++; bfs(i, j);
		}
	}

	cout << pic << '\n' << ret;

	return 0;
}