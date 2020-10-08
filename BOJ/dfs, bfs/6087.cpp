//6087
#include <bits/stdc++.h>
using namespace std;
#define INF 1000000007
#define MAX 4000005
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

struct P {
	int x, y, dir, c;
	P() : x(-1), y(-1), dir(-1), c(0) {}
	P(int a, int b, int c, int d) : x(a), y(b), dir(c), c(d) {}
};

int w, h;
int dx[] = { -1,0,1,0 }, dy[] = { 0,1,0,-1 };
int dist[105][105];
int ret = INF;
char a[105][105];

bool OOB(int x, int y) {
	if (x < 0 || x >= h || y < 0 || y >= w) return true;
	return false;
}

void bfs(P start, P end) {
	memset(dist, INF, sizeof(dist));
	queue<P> q;
	for (int i = 0; i < 4; ++i) {
		start.dir = i;
		q.push(start);
	}
	dist[start.x][start.y] = 0;
	while (!q.empty()) {
		int x = q.front().x, y = q.front().y, dir = q.front().dir, cnt = q.front().c; q.pop();
		if (a[x][y] == 'C' && x == end.x && y == end.y) {
			ret = min(ret, dist[x][y]);
			continue;
		}
		for (int i = 0; i < 4; ++i) {
			int nx = x + dx[i], ny = y + dy[i];
			if ((dir==0&&i==2)||(dir==2&&i==0)||(dir==1&&i==3)||(dir==3&&i==1)) continue;
			if (OOB(nx, ny)) continue;
			if (a[nx][ny] == '*') continue;
			int add = dir != i ? 1 : 0;
			if (dist[nx][ny] >= cnt + add) {
				dist[nx][ny] = cnt + add;
				q.push(P(nx, ny, i, dist[nx][ny]));
			}
		}
	}
	cout << ret;
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> w >> h;
	vector<P> point;
	for (int i = 0; i < h; ++i) {
		string s; cin >> s;
		for (int j = 0; j < w; ++j) {
			a[i][j] = s[j];
			if (s[j] == 'C') point.push_back(P(i, j, -1, 0));
		}
	}

	bfs(point[0], point[1]);

	return 0;
}