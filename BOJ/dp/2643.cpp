//2643
#include <bits/stdc++.h>
using namespace std;
#define INF 1000000000
#define MAX 10001
#define MOD 10007
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

int cache[101];
int n;
vii a;

int f(int cur) {
	if (cur == n) return 0;
	int& ret = cache[cur];
	if (ret != -1) return ret;
	ret = 0;
	for (int i = 0; i < n; ++i) {
		if (i == cur) continue;
		if (a[cur].first >= a[i].first && a[cur].second >= a[i].second)
			ret = max(ret, f(i) + 1);
	}
	return ret;
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	memset(cache, -1, sizeof(cache));
	cin >> n;
	a.resize(n);
	for (int i = 0; i < n; ++i) {
		int A, B; cin >> A >> B;
		if (A >= B) {
			a[i].first = A; a[i].second = B;
		}
		else {
			a[i].first = B; a[i].second = A;
		}
	}

	int ret = 0;
	for (int i = 0; i < n; ++i)
		ret = max(ret, f(i) + 1);
	cout << ret;

	return 0;
}