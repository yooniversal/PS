//3055

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
#define MAX 1001
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

struct state {
	int x, y;
	bool live;
	state() : x(-1), y(-1), live(false) {}
	state(int a, int b, bool c) : x(a), y(b), live(c) {}
};

int board[MAX][MAX];
bool chk[MAX][MAX];
int dx[] = { -1,1,0,0 }, dy[] = { 0,0,1,-1 };
int ret;
int n, m;
state S, D;
queue<state> W;

bool bfs() {
	queue<state> q;
	while (!W.empty()) {
		state curW = W.front(); W.pop();
		chk[curW.x][curW.y] = true;
		q.push(curW);
	}
	chk[S.x][S.y] = true;
	q.push(S);
	while (!q.empty()) {
		int curx = q.front().x, cury = q.front().y;
		bool live = q.front().live;
		q.pop();

		if (live)
			if (curx == D.x && cury == D.y) {
				ret = --board[curx][cury];
				return true;
			}

		for (int i = 0; i < 4; i++) {
			int nx = curx + dx[i], ny = cury + dy[i];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m || board[nx][ny] == 0) continue;
			if (!live && nx == D.x && ny == D.y) continue;
			if (chk[nx][ny]) continue;
			chk[nx][ny] = true;
			if (live) board[nx][ny] += board[curx][cury];
			q.push(state(nx, ny, live));
		}
	}
	return false;
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			char a; cin >> a;
			if (a == 'X') board[i][j] = 0;
			else if (a == '.') board[i][j] = 1;
			else if (a == 'S') S = state(i, j, true);
			else if (a == '*') W.push(state(i, j, false));
			else if (a == 'D') D = state(i, j, false);
		}
	}

	board[S.x][S.y] = 1;
	board[D.x][D.y] = 1;
	if (bfs()) cout << ret;
	else cout << "KAKTUS";

	return 0;
}