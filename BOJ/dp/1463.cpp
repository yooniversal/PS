//1463

#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <vector>
#include <deque>
#include <queue>
#include <cmath>
#include <algorithm>
#include <functional>
using namespace std;

int dp[1000001];

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;

	//dp[0] = dp[1] = 0
	//조건 3, 2, 1 순으로 작아진다라고 생각할 수 있으나 10이 반례
	for (int i = 2; i <= n; i++) {
		dp[i] = dp[i - 1] + 1;
		if (i % 2 == 0) dp[i] = min(dp[i], dp[i / 2] + 1);	//10은 2로 나누어 떨어지지만 dp[9]+1 < dp[10/2]+1 이므로
															//min을 통해 제일 작은 값을 취한다
		if (i % 3 == 0) dp[i] = min(dp[i], dp[i / 3] + 1);
	}

	cout << dp[n];

	return 0;
}