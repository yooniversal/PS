//2491
#include <bits/stdc++.h>
using namespace std;
#define INF 1000000007
#define MAX 4000005
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

int cache[100001], cache2[100001];
int n;
vi a;

int f(int cur) {
	if (cur == n-1) return 1;
	int& ret = cache[cur];
	if (ret != -1) return ret;
	ret = 1;
	if (a[cur] <= a[cur + 1]) ret = f(cur + 1) +1;
	return ret;
}

int g(int cur) {
	if (cur == n - 1) return 1;
	int& ret = cache2[cur];
	if (ret != -1) return ret;
	ret = 1;
	if (a[cur] >= a[cur + 1]) ret = g(cur + 1) +1;
	return ret;
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	memset(cache, -1, sizeof(cache));
	memset(cache2, -1, sizeof(cache2));
	cin >> n;
	a.resize(n);
	for (int i = 0; i < n; ++i) cin >> a[i];
	int ret = 0;
	for (int i = 0; i < n; ++i) {
		ret = max(ret, max(f(i), g(i)));
	}
	cout << ret;

	return 0;
}