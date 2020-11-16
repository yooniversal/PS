//2151
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
	int x, y, c, d;
};

int dx[] = { -1,1,0,0 }, dy[] = { 0,0,1,-1 };
int chk[51][51][2];
int n;
vector<string> a;
P st;

bool OOB(int x, int y) {
	if (x < 0 || x >= n || y < 0 || y >= n) return true;
	return false;
}

int BFS() {
	int ret = INF;
	queue<P> q;
	st.d = 0;
	q.push(st);
	st.d = 1;
	q.push(st);

	for (int i = 0; i < 51; ++i)
		for (int j = 0; j < 51; ++j)
			chk[i][j][0] = chk[i][j][1] = INF;
	chk[st.x][st.y][0] = chk[st.x][st.y][1] = 0;

	while (!q.empty()) {
		int x = q.front().x, y = q.front().y, cnt = q.front().c, dir = q.front().d; q.pop();
		if (ret < cnt) continue;
		if (a[x][y] == '#' && !(x == st.x && y == st.y)) {
			if (ret > cnt) ret = cnt;
			continue;
		}

		for (int i = 0; i < 4; ++i) {
			if (dir == 0) {
				if (i >= 2) continue;
			}
			else
				if (i <= 1) continue;
			int nx = x + dx[i], ny = y + dy[i];
			if (OOB(nx, ny)) continue;
			if (a[nx][ny] == '*') continue;
			if (a[nx][ny] == '!') {
				//방향 바꾸기
				if (chk[nx][ny][!dir] > cnt+1) {
					chk[nx][ny][!dir] = cnt+1;
					q.push({ nx, ny, cnt + 1, !dir });
				}
				//그대로 가기
				if (chk[nx][ny][dir] > cnt) {
					chk[nx][ny][dir] = cnt;
					q.push({ nx, ny, cnt, dir });
				}
			}
			else {
				if (chk[nx][ny][dir] <= cnt) continue;
				chk[nx][ny][dir] = cnt;
				q.push({ nx, ny, cnt, dir });
			}
		}
	}
	return ret;
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n;
	for (int i = 0; i < n; ++i) {
		string s; cin >> s;
		a.push_back(s);
		for(int j=0; j<n; ++j)
			if (s[j] == '#') {
				st.x = i;
				st.y = j;
				st.c = 0;
			}
	}

	cout << BFS();

	return 0;
}