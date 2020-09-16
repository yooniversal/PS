//1261

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
#define MAX 101
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

struct state {
	int x, y, s;
	state() : x(-1), y(-1), s(-1) {}
	state(int a, int b, int c) : x(a), y(b), s(c) {}
};

struct cmp {
	bool operator()(state& a, state& b){
		return a.s > b.s;
	}
};

int dx[] = { -1, 1, 0, 0 }, dy[] = { 0, 0, 1, -1 };
int board[MAX][MAX];
int n, m;
int ret;
bool chk[MAX][MAX];

void bfs() {
	priority_queue<state, vector<state>, cmp> pq;
	chk[0][0] = true;
	pq.push(state(0, 0, 0));
	while (!pq.empty()) {
		state cur = pq.top(); pq.pop();
		if (cur.x == n - 1 && cur.y == m - 1) {
			ret = cur.s;
			break;
		}

		for (int i = 0; i < 4; i++) {
			int nx = cur.x + dx[i], ny = cur.y + dy[i];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m || chk[nx][ny]) continue;
			chk[nx][ny] = true;
			if (board[nx][ny]) pq.push(state(nx, ny, cur.s + 1));
			else pq.push(state(nx, ny, cur.s));
		}
	}

}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> m >> n;
	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		for (int j = 0; j < m; j++) {
			board[i][j] = s[j] - '0';
		}
	}

	bfs();
	cout << ret;

	return 0;
}