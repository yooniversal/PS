//2210
#include <bits/stdc++.h>
using namespace std;
#define INF 1000000001
#define MAX 100005
#define MOD 1000000000
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

struct P {
	int x, y;
	string s;
	P(int a, int b, string c) : x(a), y(b), s(c) {}
};
int a[6][6];
int dx[] = { -1,1,0,0 }, dy[] = { 0,0,1,-1 };

bool OOB(int x, int y) {
	if (x < 0 || x >= 5 || y < 0 || y >= 5) return true;
	return false;
}

int BFS() {
	queue<P> q;
	for (int i = 0; i < 5; ++i)
		for (int j = 0; j < 5; ++j)
			q.push(P(i, j, ""));
	map<string, bool> m;
	int ret = 0;
	while (!q.empty()) {
		int x = q.front().x, y = q.front().y;
		string s = q.front().s; q.pop();
		s += a[x][y] + '0';
		if (s.size() >= 6) {
			if (m[s]) continue;
			m[s] = true;
			++ret;
			continue;
		}
		for (int i = 0; i < 4; ++i) {
			int nx = x + dx[i], ny = y + dy[i];
			if (OOB(nx, ny)) continue;
			q.push(P(nx, ny, s));
		}
	}
	return ret;
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	for (int i = 0; i < 5; ++i)
		for (int j = 0; j < 5; ++j)
			cin >> a[i][j];
	cout << BFS();

	return 0;
}