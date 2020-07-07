//1912

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max(a, b) (((a)>(b)) ? (a) : (b))

//dp 공간을 매번 발생하는 연속합으로 업데이트 해준다
//항상 연속합의 최대를 저장해야 한다는 고정관념을 버리자
long long int dp[100001];
long long int arr[100001];

//dp중의 최댓값이 연속합의 최대
long long int getMax(int n) {
	long long int max;

	max = dp[1];
	for (int i = 1; i <= n; i++)
		if (max < dp[i])
			max = dp[i];

	return max;
}

long long int savedp(int n) {
	if (n == 1) {
		dp[1] = arr[1];
		return dp[1];
	}
	
	if (dp[n]) return dp[n];
	else {
		//이전 연속합(dp[n-1])과 arr[n]을 더하거나, arr[n]의 값중 큰 값이 다음 연속합이 된다
		dp[n] = max(savedp(n-1)+arr[n], arr[n]);
		return dp[n];
	}
}

int main() {
	int n;

	scanf("%d", &n);

	for (int i = 1; i <= n; i++)
		scanf("%lld", &arr[i]);

	savedp(n);
	printf("%lld ", getMax(n));

	return 0;
}