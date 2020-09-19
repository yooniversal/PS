//16194
#include <bits/stdc++.h>
using namespace std;
#define INF 1000000001
#define MAX 10005
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

int a[MAX];
int cache[MAX];
int n, k;

int f(int cur) {
	if (cur < 0) return INF;
	if (cur == 0) return 0;
	int& ret = cache[cur];
	if (ret != -1) return ret;

	ret = INF;
	for (int i = 0; i < n; ++i) {
		ret = min(ret, f(cur - (i+1)) + a[i]);
	}

	return ret;
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	memset(cache, -1, sizeof(cache));

	cin >> n;
	for (int i = 0; i < n; ++i) cin >> a[i];

	cout << f(n);

	return 0;
}