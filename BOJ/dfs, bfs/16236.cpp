//16236
#include <bits/stdc++.h>
using namespace std;
#define INF 1000000001
#define MAX 4005
#define MOD 1000000000
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

struct P {
	int x, y, move, size;
};

int dx[] = { -1, 1, 0, 0 }, dy[] = { 0,0,1,-1 };
int n, a[21][21];
bool chk[21][21];

bool OOB(int x, int y) {
	if (x < 0 || x >= n || y < 0 || y >= n) return true;
	return false;
}

P BFS(P st) {
	memset(chk, 0, sizeof(chk));
	int MOVE = INF;
	vector<P> tmp;
	queue<P> q;
	chk[st.x][st.y] = true;
	q.push(st);
	while (!q.empty()) {
		int x = q.front().x, y = q.front().y, move = q.front().move;
		int size = q.front().size; q.pop();
		if (MOVE < move) continue;
		if (size > a[x][y] && a[x][y]) {
			MOVE = min(MOVE, move);
			tmp.push_back({ x, y, move, size });
		}

		for (int i = 0; i < 4; ++i) {
			int nx = x + dx[i], ny = y + dy[i];
			if (OOB(nx, ny)) continue;
			if (a[nx][ny] > size) continue;
			if (chk[nx][ny]) continue;
			chk[nx][ny] = true;
			q.push({ nx, ny, move + 1, size });
		}
	}

	P ret = { INF, INF, INF, INF };
	for (int i = 0; i < tmp.size(); ++i) {
		if (tmp[i].x < ret.x)
			ret = tmp[i];
		else if (tmp[i].x == ret.x) {
			if (tmp[i].y < ret.y)
				ret = tmp[i];
		}
	}
	return ret;
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	P st;
	cin >> n;
	for(int i=0; i<n; ++i)
		for (int j = 0; j < n; ++j) {
			cin >> a[i][j];
			if (a[i][j] == 9) {
				st.x = i;
				st.y = j;
				a[i][j] = 0;
			}
		}
	st.move = 0, st.size = 2;
	int ret = 0, cnt = 0;
	while (1) {
		P cur = BFS(st);
		st = cur;
		if (st.x == INF) break;
		a[st.x][st.y] = 0;
		if (++cnt == st.size) {
			++st.size;
			cnt = 0;
		}
		ret += st.move;
		st.move = 0;
	}
	cout << ret;

	return 0;
}