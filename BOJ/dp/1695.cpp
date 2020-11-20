//1695
#include <bits/stdc++.h>
using namespace std;
#define INF 1000000000
#define MAX 605
#define MOD 1000000007
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

int cache[5005][5005];
int n;
vi a;

int f(int l, int r) {
	if (l == r) return f(l - 1, r + 1) + 1;
	if (l <= 0 || r >= n + 1) return 0;
	int& ret = cache[l][r];
	if (ret != -1) return ret;
	ret = 0;
	if (a[l] == a[r]) {
		ret = max(ret, f(l - 1, r + 1) + 2);
	}
	else {
		ret = max(ret, f(l - 1, r));
		ret = max(ret, f(l, r + 1));
	}
	return ret;
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	memset(cache, -1, sizeof(cache));
	cin >> n;
	a.resize(n + 1, 0);
	for (int i = 1; i <= n; ++i) cin >> a[i];
	int ret = 0;
	for (int i = 1; i <= n; ++i) {
		ret = max(ret, f(i, i));
		if (i <= n - 1 && a[i] == a[i + 1]) ret = max(ret, f(i, i + 1));
	}
	cout << n - ret;

	return 0;
}