//1633
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
const int MAX = 1001, INF = 1000000001, MOD = 1234567;

int cache[MAX][16][16];
vii p;

int f(int cur, int a, int b) {
	if (a > 15 || b > 15) return -INF;
	if (a == 15 && b == 15) return 0;
	if (cur == p.size()) return -INF;
	int& ret = cache[cur][a][b];
	if (ret != -1) return ret;
	ret = 0;
	ret = max(ret, f(cur + 1, a, b));
	ret = max(ret, f(cur + 1, a + 1, b) + p[cur].first);
	ret = max(ret, f(cur + 1, a, b + 1) + p[cur].second);
	return ret;
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	memset(cache, -1, sizeof(cache));
	int a, b;
	while (cin>>a>>b) {
		p.push_back({ a,b });
	}

	cout << f(0, 0, 0) << '\n';

	return 0;
}