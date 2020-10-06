//9376
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
	int x, y;
};

bool key[27], chk[105][105];
char a[105][105];
int dx[] = { -1,1,0,0 }, dy[] = { 0,0,1,-1 };
int n, m, ret;

bool OOB(int x, int y) {
	if (x<0 || x>n + 1 || y<0 || y>m + 1) return true;
	return false;
}

void bfs() {
	memset(chk, 0, sizeof(chk));
	queue<P> q;
	q.push({ 0,0 });
	chk[0][0] = true;
	while (!q.empty()) {
		int x = q.front().x, y = q.front().y; q.pop();
		for (int i = 0; i < 4; ++i) {
			int nx = x + dx[i], ny = y + dy[i];
			if (OOB(nx, ny)) continue;
			if (chk[nx][ny]) continue;
			chk[nx][ny] = true;
			if (a[nx][ny] == '*') continue;
			if ('A' <= a[nx][ny] && a[nx][ny] <= 'Z')
				if (!key[a[nx][ny] - 'A']) continue;
			if ('a' <= a[nx][ny] && a[nx][ny] <= 'z')
				key[a[nx][ny] - 'a'] = true;
			if (a[nx][ny] == '$') {
				a[nx][ny] = '.'; ++ret;
			}
			q.push({ nx, ny });
		}
	}
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int t; cin >> t;
	while (t--) {
		ret = 0;
		memset(key, 0, sizeof(key));

		cin >> n >> m;
		for(int i=0; i<n+2; ++i)
			for (int j = 0; j < m + 2; ++j) {
				if (i == 0 || i == n + 1 || j == 0 || j == m + 1) a[i][j] = '.';
				else {
					char ch; cin >> ch;
					a[i][j] = ch;
				}
			}
		string keys; cin >> keys;
		if(keys != "0")
			for (int i = 0; i < keys.size(); ++i)
				key[keys[i] - 'a'] = true;

		for (int i = 0; i < 27; ++i) {
			bfs();
		}
		cout << ret << '\n';
	}

	return 0;
}