//11060
#include <bits/stdc++.h>
using namespace std;
#define INF 1000000000
#define MAX 4000005
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

int cache[1005];
int n;
vi a;

int f(int cur) {
	//cout << "*cur:" << cur << '\n';
	if (cur > n-1) return INF;
	if (cur == n-1) return 0;
	int& ret = cache[cur];
	if (ret != -1) return ret;
	ret = INF;

	for (int i = 1; i <= a[cur]; ++i) {
		ret = min(ret, f(cur + i) + 1);
	}
	return ret;
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	memset(cache, -1, sizeof(cache));
	cin >> n;
	a.resize(n+1);
	for (int i = 0; i < n; ++i) cin >> a[i];
	if (f(0) == INF) cout << -1;
	else cout << f(0);

	return 0;
}