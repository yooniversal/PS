//11066

#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <vector>
#include <deque>
#include <cmath>
#include <algorithm>
using namespace std;
#define INF 987654321

int dp[501][501];
int cost[501];
int sum[501];

int dpf(int s, int e) {

	if (s >= e) return 0;
	if (dp[s][e] != -1) return dp[s][e];
	if (s + 1 == e) return cost[s] + cost[e];

	dp[s][e] = INF;
	
	//dp[s][i] + dp[i+1][e] + 부분합(s~e)의 최소를 dp[s][e]에 업데이트
	for (int i = s; i <= e; i++)
		dp[s][e] = min(dp[s][e], dpf(s, i) + dpf(i + 1, e) + sum[e] - sum[s - 1]);

	return dp[s][e];
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int t, n;
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> cost[i];
			sum[i] = sum[i - 1] + cost[i];
			for (int j = 1; j <= n; j++) {
				dp[i][j] = -1;
			}
		}

		cout << dpf(1, n) << endl;
	}
	

	return 0;
}