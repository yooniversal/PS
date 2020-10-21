//2616
#include <bits/stdc++.h>
using namespace std;
#define INF 1000000001
#define MAX 100005
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

int cache[50001][4];
int n, k;
vi arr, pSum;

int f(int a, int b) {
	if (a+k > n && b > 0) return -INF;
	if (b == 0) return 0;
	int& ret = cache[a][b];
	if (ret != -1) return ret;
	ret = 0;
	ret = max(ret, f(a + 1, b));
	ret = max(ret, f(a + k, b - 1) + pSum[a + k] - pSum[a]);
	return ret;
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	memset(cache, -1, sizeof(cache));
	cin >> n; arr.resize(n); pSum.resize(n + 1, 0);
	for (int i = 0; i < n; ++i) cin >> arr[i];
	for (int i = 1; i <= n; ++i) pSum[i] = pSum[i - 1] + arr[i - 1];
	cin >> k;
	cout << f(0, 3);

	return 0;
}