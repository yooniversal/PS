//1912

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max(a, b) (((a)>(b)) ? (a) : (b))

//dp ������ �Ź� �߻��ϴ� ���������� ������Ʈ ���ش�
//�׻� �������� �ִ븦 �����ؾ� �Ѵٴ� ���������� ������
long long int dp[100001];
long long int arr[100001];

//dp���� �ִ��� �������� �ִ�
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
		//���� ������(dp[n-1])�� arr[n]�� ���ϰų�, arr[n]�� ���� ū ���� ���� �������� �ȴ�
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