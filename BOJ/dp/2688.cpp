//2688
#include <bits/stdc++.h>
using namespace std;
#define INF 1000000001
#define MAX 100005
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

ll cache[65][10];
int n;
ll f(int cur, int a) {
	if (cur == n) return 1;
	ll& ret = cache[cur][a];
	if (ret != -1) return ret;
	ret = 0;
	for (int i = a; i <= 9; ++i)
		ret += f(cur + 1, i);
	return ret;
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int t; cin >> t;
	while (t--) {
		memset(cache, -1, sizeof(cache));
		cin >> n;
		cout << f(0, 0) << '\n';
	}

	return 0;
}