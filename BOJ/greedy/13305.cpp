//13305
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
const int MAX = 100005, INF = 1000000001, MOD = 9901;

int n;
int cost[100001], dist[100001];

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n;
	for (int i = 0; i < n - 1; ++i) cin >> dist[i];
	for (int i = 0; i < n; ++i) cin >> cost[i];

	ll sumDist = 0, ret = 0;
	int cur = cost[0];
	for (int i = 0; i < n-1; ++i) {
		if (cur > cost[i]) {
			ret += sumDist * cur;
			cur = cost[i];
			sumDist = dist[i];
		}
		else {
			sumDist += dist[i];
		}
	}
	if (sumDist) {
		ret += sumDist * cur;
	}
	cout << ret << '\n';

	return 0;
}