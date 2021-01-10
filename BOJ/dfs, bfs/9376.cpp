//9376
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
const int MAX = 100001, INF = 1000000001, MOD = 1234567;

struct P {
	int x, y;
};

const int dx[] = { -1,1,0,0 }, dy[] = { 0,0,1,-1 };
int board[105][105];
int d[105][105][3];
int h, w;
deque<P> person;

bool OOB(int x, int y) {
	if (x < 0 || x > h + 1 || y < 0 || y > w + 1) return true;
	return false;
}

void bfs() {
	person.push_back({ 0,0 });
	for (int turn = 0; turn < 3; ++turn) {
		int cx = person.back().x, cy = person.back().y; person.pop_back();
		deque<P> q;
		q.push_back({ cx, cy });
		while (!q.empty()) {
			int x = q.front().x, y = q.front().y; q.pop_front();
			if (d[x][y][turn] == -1) d[x][y][turn] = 0;
			for (int i = 0; i < 4; ++i) {
				int nx = x + dx[i], ny = y + dy[i];
				if (OOB(nx, ny)) continue;
				if (d[nx][ny][turn] != -1) continue;
				if (board[nx][ny] == -1) continue;
				if (board[nx][ny] == 0) {
					d[nx][ny][turn] = d[x][y][turn];
					q.push_front({ nx, ny });
				}
				else {
					d[nx][ny][turn] = d[x][y][turn] + 1;
					q.push_back({ nx, ny });
				}
			}
		}
	}
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int t; cin >> t;
	while (t--) {
		memset(board, 0, sizeof(board));
		memset(d, -1, sizeof(d));

		cin >> h >> w;
		for (int i = 0; i < h + 2; ++i) {
			if (i == 0 || i == h + 1) continue;
			string s; cin >> s;
			for (int j = 0; j < w; ++j) {
				if (s[j] == '*') board[i][j + 1] = -1;
				else if (s[j] == '#') board[i][j + 1] = 1;
				else if (s[j] == '$') person.push_back({ i,j + 1 });
			}
		}

		bfs();

		int ret = INF;
		for (int i = 0; i < h + 2; ++i)
			for (int j = 0; j < w + 2; ++j) {
				int dist = d[i][j][0] + d[i][j][1] + d[i][j][2];
				if (d[i][j][0] == -1 || d[i][j][1] == -1 || d[i][j][2] == -1) continue;
				if (board[i][j] == -1) continue;
				if (board[i][j] == 1) dist -= 2;
				ret = min(ret, dist);
			}
		cout << ret << '\n';
	}

	return 0;
}