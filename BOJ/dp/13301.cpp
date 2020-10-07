//13301
#include <bits/stdc++.h>
using namespace std;
#define INF 1000000000
#define MAX 4000005
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

ll cache[81];

ll f(int cur) {
	if (cur == 1) return 4;
	if (cur == 2) return 6;
	ll& ret = cache[cur];
	if (ret != -1) return ret;
	ret = f(cur - 1) + f(cur - 2);
	return ret;
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	memset(cache, -1, sizeof(cache));
	int n; cin >> n;
	cout << f(n);

	return 0;
}