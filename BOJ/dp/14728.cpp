//14728
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
const int MAX = 100001, INF = 1000000001;

int n, t;
int cache[101][10001];
vii q;

int f(int cur, int remain) {
	if (cur == n || remain == 0) return 0;
	int& ret = cache[cur][remain];
	ret = 0;
	if (remain >= q[cur].first) ret = max(ret, f(cur+1, remain - q[cur].first) + q[cur].second);
	ret = max(ret, f(cur + 1, remain));
	return ret;
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	memset(cache, -1, sizeof(cache));
	cin >> n >> t;
	q.resize(n);
	for (int i = 0; i < n; ++i) cin >> q[i].first >> q[i].second;
	cout << f(0, t) << '\n';

	return 0;
}