//15685
#include <bits/stdc++.h>
using namespace std;
#define INF 1000000001
#define MAX 100005
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

bool a[101][101];
int dx[] = { 0,-1,0,1 }, dy[] = { 1,0,-1,0 };

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n; cin >> n;
	while (n--) {
		int x, y, d, g; cin >> y >> x >> d >> g;
		a[x][y] = true;
		x += dx[d], y += dy[d];
		a[x][y] = true;
		//printf("1st: x:%d y:%d\n", x, y);
		vi dirs; dirs.push_back(d);
		while (g--) {
			int SIZE = dirs.size();
			for (int i = SIZE - 1; i >= 0; --i) {
				int nd = (dirs[i] + 1) % 4;
				dirs.push_back(nd);
				x += dx[nd], y += dy[nd];
				a[x][y] = true;
				//printf("@st: x:%d y:%d\n", x, y);
			}
		}
	}

	int ret = 0;
	for (int i = 0; i < 100; ++i)
		for (int j = 0; j < 100; ++j)
			if (a[i][j] && a[i][j + 1] && a[i + 1][j] && a[i + 1][j + 1])
				++ret;
	cout << ret;

	return 0;
}