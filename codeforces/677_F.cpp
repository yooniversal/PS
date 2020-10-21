#include <bits/stdc++.h>
using namespace std;
#define INF 1000000001
#define MAX 300005
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

int cache[71][71][71][71];
int n, m, k;
int arr[71][71];

int f(int row, int col, int sum, int cnt) {
	if (row == n) return sum == 0 ? 0 : -INF;
	int& ret = cache[row][col][sum][cnt];
	if (ret != -1) return ret;
	if (col == m || cnt == m/2)	return ret = f(row + 1, 0, sum, 0);
	ret = 0;
	if (cnt < m / 2) {
		ret = max(ret, f(row, col + 1, ((sum - (arr[row][col]) % k) + k) % k, cnt + 1) + arr[row][col]);
		ret = max(ret, f(row, col + 1, sum, cnt));
	}
	return ret;
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	memset(cache, -1, sizeof(cache));
	cin >> n >> m >> k;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			cin >> arr[i][j];
	cout << f(0, 0, 0, 0);

	return 0;
}