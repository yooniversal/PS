//2208
#include <bits/stdc++.h>
using namespace std;
#define INF 1000000001
#define MAX 100005
#define MOD 1000000007
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m; cin >> n >> m;
	vi pSum(n + 1, 0);
	for (int i = 0; i < n; ++i) {
		int x; cin >> x;
		pSum[i + 1] = pSum[i] + x;
	}
	
	int tmp = 0, ret = 0;
	for (int i = m - 1; i < n; ++i) {
		tmp = min(tmp, pSum[i - m + 1]);
		ret = max(ret, pSum[i + 1] - tmp);
	}
	cout << ret << '\n';

	return 0;
}