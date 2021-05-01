//2156
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
const int MAX = 100005, INF = 1000000001, MOD = 9901;

int n, a[10001];
int cache[10001][3];

int f(int p, int cnt) {
	if (p >= n) return 0;
	int& ret = cache[p][cnt];
	if (ret != -1) return ret;
	ret = f(p + 1, 0);
	if (cnt < 2) ret = max(ret, f(p + 1, cnt + 1) + a[p]);
	return ret;
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	memset(cache, -1, sizeof(cache));
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	cout << f(0, 0) << '\n';

	return 0;
}