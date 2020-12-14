//16953
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
const int MAX = 10000001, INF = 1000000001, MOD = 1234567;

ll a, b;
int ret = INF;

void DFS(ll cur, int cnt) {
	if (cur > b) return;
	if (cur == b) {
		ret = min(ret, cnt);
		return;
	}
	DFS(cur * 2, cnt + 1);
	DFS(cur * 10 + 1, cnt + 1);
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> a >> b;
	DFS(a, 1);
	if (ret == INF) cout << -1 << '\n';
	else cout << ret << '\n';

	return 0;
}