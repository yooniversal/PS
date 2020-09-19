//2294
#include <bits/stdc++.h>
using namespace std;
#define INF 1000000001
#define MAX 10001
#define MOD 1000000009
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

int a[105];
int cache[MAX];
int n, k;

int f(int cur) {
	if (cur < 0) return INF;
	if (cur == 0) return 0;
	int& ret = cache[cur];
	if (ret != -1) return ret;
	
	ret = INF;
	for (int i = 0; i < n; ++i) {
		ret = min(ret, f(cur - a[i]) + 1);
	}

	return ret;
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	memset(cache, -1, sizeof(cache));

	cin >> n >> k;
	for (int i = 0; i < n; ++i) cin >> a[i];
	sort(a, a + n);
	
	if (f(k) != INF) cout << f(k);
	else cout << -1;

	return 0;
}