//17404
#include <bits/stdc++.h>
using namespace std;
#define INF 1000000001
#define MAX 1001
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

int a[MAX][3];
int cache[MAX][3][3];
int n;

int f(int r, int c, int top) {
	if (r == 0) {
		if (c == top) return INF;
		return a[r][c];
	}
	int& ret = cache[r][c][top];
	if (ret != -1) return ret;

	ret = INF;
	for (int i = 0; i < 3; i++) {
		if (r == n - 1) {
			if (i != top)
				ret = min(ret, f(r - 1, i, top) + a[r][top]);
		}
		else {
			if (i != c)
				ret = min(ret, f(r - 1, i, top) + a[r][c]);
		}
	}

	return ret;
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	memset(cache, -1, sizeof(cache));

	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < 3; j++)
			cin >> a[i][j];

	int ans = INF;
	for (int i = 0; i < 3; i++)
		ans = min(ans, f(n-1, i, i));

	cout << ans;

	return 0;
}