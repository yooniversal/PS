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
	//���� 3, 2, 1 ������ �۾����ٶ�� ������ �� ������ 10�� �ݷ�
	for (int i = 2; i <= n; i++) {
		dp[i] = dp[i - 1] + 1;
		if (i % 2 == 0) dp[i] = min(dp[i], dp[i / 2] + 1);	//10�� 2�� ������ ���������� dp[9]+1 < dp[10/2]+1 �̹Ƿ�
															//min�� ���� ���� ���� ���� ���Ѵ�
		if (i % 3 == 0) dp[i] = min(dp[i], dp[i / 3] + 1);
	}

	cout << dp[n];

	return 0;
}