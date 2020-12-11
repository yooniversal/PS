//16938
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
const int MAX = 1001, INF = 1000000001, MOD = 1234567;

int n, l, r, x, ret;
vi prb;

void DFS(int prev, int cnt, int sum, int minn, int maxx) {
	if (cnt >= 2) if ((l <= sum && sum <= r) && (maxx - minn >= x)) ++ret;
	if (cnt == n) return;
	for (int i = prev+1; i < n; ++i) {
		DFS(i, cnt + 1, sum + prb[i], min(minn, prb[i]), max(maxx, prb[i]));
	}
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n >> l >> r >> x;
	prb.resize(n);
	for (int i = 0; i < n; ++i) cin >> prb[i];
	DFS(-1, 0, 0, INF, 0);
	cout << ret << '\n';

	return 0;
}