//15678
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

ll dp[100001];

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, d; cin >> n >> d;
	vi a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		dp[i] = -INF;
	}
	
	ll ret = -INF;
	deque<int> dq;
	for (int i = 0; i < n; ++i) {
		while (!dq.empty()) {
			if (dq.front() < i - d) dq.pop_front();
			else break;
		}
		ll prev = max(0LL, !dq.empty() ? dp[dq.front()] : 0LL);
		dp[i] = prev + a[i];
		ret = max(ret, dp[i]);
		while (!dq.empty()) {
			if (dp[dq.back()] <= dp[i]) dq.pop_back();
			else break;
		}
		dq.push_back(i);
	}
	cout << ret << '\n';

	return 0;
}