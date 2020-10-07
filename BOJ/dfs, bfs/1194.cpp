//1194
#include <bits/stdc++.h>
using namespace std;
#define INF 1000000000
#define MAX 4000005
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

struct P {
	int x, y, cnt, key;
	P() :x(-1), y(-1), cnt(0), key(0) {}
	P(int a, int b, int c, int d) :x(a), y(b), cnt(c), key(d) {}
};

char a[51][51];
bool chk[1<<6][51][51];
int dx[] = { -1,1,0,0 }, dy[] = { 0,0,1,-1 };
int n, m;

bool OOB(int x, int y) {
	if (x<0 || x>=n || y<0 || y>=m) return true;
	return false;
}

int bfs(P start) {
	queue<P> q;
	q.push(start);
	chk[0][start.x][start.y] = true;
	while (!q.empty()) {
		int x = q.front().x, y = q.front().y;
		int cnt = q.front().cnt, key = q.front().key;
		q.pop();
		if (a[x][y] == '1') return cnt;
		for (int i = 0; i < 4; ++i) {
			int nx = x + dx[i], ny = y + dy[i];
			if (OOB(nx, ny)) continue;
			if (a[nx][ny] == '#') continue;
			if (chk[key][nx][ny]) continue;
			chk[key][nx][ny] = true;
			if ('A' <= a[nx][ny] && a[nx][ny] <= 'F')
				if (!(key & (1<<(a[nx][ny] - 'A')))) continue;
			if ('a' <= a[nx][ny] && a[nx][ny] <= 'f')
				q.push(P(nx, ny, cnt + 1, key | (1<<(a[nx][ny]-'a'))));
			else 
				q.push(P(nx, ny, cnt + 1, key));
		}
	}
	return -1;
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	P st;
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		string s; cin >> s;
		for (int j = 0; j < m; ++j) {
			a[i][j] = s[j];
			if (s[j] == '0') {
				st.x = i; st.y = j;
			}
		}
	}

	cout << bfs(st);

	return 0;
}