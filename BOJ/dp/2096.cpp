//2096
#include <bits/stdc++.h>
using namespace std;
#define INF 1000000001
#define MAX 100001
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

int a[MAX][3];
int cache[2][3];
int n;
int dy[] = { -1, 0, 1 };

bool OOB(int x, int y) {
	if (x < 0 || x >= n || y < 0 || y >= 3) return true;
	return false;
}

int f() {
	cache[0][0] = a[0][0];
	cache[0][1] = a[0][1];
	cache[0][2] = a[0][2];

	for (int curx = 0; curx < n-1; ++curx) {
		for (int cury = 0; cury < 3; ++cury) {
			for (int i = 0; i < 3; ++i) {
				int nx = curx + 1, ny = cury + dy[i];
				if (OOB(nx, ny)) continue;
				cache[1][ny] = max(cache[1][ny], cache[0][cury] + a[nx][ny]);
			}
		}
		cache[0][0] = cache[1][0];
		cache[0][1] = cache[1][1];
		cache[0][2] = cache[1][2];
		cache[1][0] = cache[1][1] = cache[1][2] = 0;
	}

	return max(cache[0][0], max(cache[0][1], cache[0][2]));
}

int g() {
	cache[0][0] = a[0][0];
	cache[0][1] = a[0][1];
	cache[0][2] = a[0][2];

	for (int curx = 0; curx < n-1; ++curx) {
		for (int cury = 0; cury < 3; ++cury) {
			for (int i = 0; i < 3; ++i) {
				int nx = curx + 1, ny = cury + dy[i];
				if (OOB(nx, ny)) continue;
				cache[1][ny] = min(cache[1][ny], cache[0][cury] + a[nx][ny]);
			}
		}
		cache[0][0] = cache[1][0];
		cache[0][1] = cache[1][1];
		cache[0][2] = cache[1][2];
		cache[1][0] = cache[1][1] = cache[1][2] = INF;
	}

	return min(cache[0][0], min(cache[0][1], cache[0][2]));
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < 3; ++j)
			cin >> a[i][j];

	cout << f() << '\n';
	for (int i = 0; i < 3; ++i) cache[1][i] = INF;
	cout << g();

	return 0;
}