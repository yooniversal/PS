//12865

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max(a, b) (((a)>(b)) ? (a) : (b))

//dp[i][j] : value   i : item's name  j : item's weight
long long int dp[105][100005];

int main() {
	int N, K, W, V, cnt;
	int warr[101], varr[101];

	//N:���̽� ����  K:���� ����
	scanf("%d %d", &N, &K);
	
	cnt = 1;

	for (int i = 1; i <= N; i++)
		scanf("%d %d", &warr[i], &varr[i]);

	while (cnt != N+1) {
		//input weight and value
		W = warr[cnt];
		V = varr[cnt];

		//process
		//dp�� ���������� �̹� 0���� ä���� ����
		//0���� ���� �ʱ�ȭ���� �ʿ䰡 ����, ���� 1���� ������ �ʱ�ȭ���� �ʾƵ� ��
		//j : ���� ���� (1���� K���� value ���� �ݿ����ֱ� ����)
		for (int j = 1; j <= K; j++)
			//�ش� ���԰� ���� ������ ���� ���, Value�� �߰����� ���ϱ� ������ ���� value�� �����´�
			if (W > j) dp[cnt][j] = dp[cnt - 1][j];
			//���� ���� j�� ���� ���� W���� Ŭ ���, ���� value�� �ش� ������ �߰����� �� �׸��� ���� value �� ū ���� ����(DP)
			else dp[cnt][j] = max(dp[cnt - 1][j], dp[cnt - 1][j - W] + V);
		
		cnt++;
	}

	printf("%lld", dp[N][K]);

	return 0;
}