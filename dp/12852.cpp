//12852

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
int tmp[1000001];

//각 숫자마다 모든 경우의 수를 저장하는게 아님
//DP를 통해 따라가면서 재귀 호출을 통해 출력
void printtmp(int n) {

	if (tmp[n] != 0) {
		cout << tmp[n] << " ";
		printtmp(tmp[n]);
	}
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;

	for (int i = 2; i <= n; i++) {
		int mode = 1;
		dp[i] = dp[i - 1] + 1;
		if (i % 2 == 0) {
			if (min(dp[i], dp[i / 2] + 1) == dp[i]) dp[i] = dp[i];
			else {
				dp[i] = dp[i / 2] + 1;
				mode = 2;
			}
		}
		if (i % 3 == 0) {
			if (min(dp[i], dp[i / 3] + 1) == dp[i]) dp[i] = dp[i];
			else {
				dp[i] = dp[i / 3] + 1;
				mode = 3;
			}
		}
		if (mode == 1) tmp[i] = i - 1;
		else if (mode == 2) tmp[i] = i / 2;
		else tmp[i] = i / 3;
	}

	cout << dp[n] << '\n' << n << " ";
	printtmp(n);

	return 0;
}