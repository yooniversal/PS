//15989
#include <bits/stdc++.h>
using namespace std;
#define INF 1000000007
#define MAX 4000005
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

int cache[10001][4];
int n;

int f(int cur, int p) {
	if (cur > n) return 0;
	if (cur == n) return 1;
	int& ret = cache[cur][p];
	if (ret != -1) return ret;
	ret = 0;
	for (int i = 1; i <= p; ++i)
		ret += f(cur + i, i);
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
		cout << f(0, 3) << '\n';
	}

	return 0;
}