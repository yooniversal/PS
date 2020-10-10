//10835
#include <bits/stdc++.h>
using namespace std;
#define INF 1000000007
#define MAX 4000005
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

int cache[2001][2001][3];
int n;
vi a, b;

int f(int l, int r, int rule) {
	if (l == n || r == n) return 0;
	int& ret = cache[l][r][rule];
	if (ret != -1) return ret;
	ret = 0;
	ret = max(ret, f(l + 1, r + 1, 0));
	ret = max(ret, f(l + 1, r, 1));
	if (a[l] > b[r]) ret = max(ret, f(l, r + 1, 2) + b[r]);
	return ret;
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	memset(cache, -1, sizeof(cache));
	cin >> n;
	a.resize(n); b.resize(n);
	for (int i = 0; i < n; ++i) cin >> a[i];
	for (int i = 0; i < n; ++i) cin >> b[i];
	cout << f(0, 0, 0);

	return 0;
}