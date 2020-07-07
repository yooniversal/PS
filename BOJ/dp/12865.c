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

	//N:케이스 개수  K:무게 제한
	scanf("%d %d", &N, &K);
	
	cnt = 1;

	for (int i = 1; i <= N; i++)
		scanf("%d %d", &warr[i], &varr[i]);

	while (cnt != N+1) {
		//input weight and value
		W = warr[cnt];
		V = varr[cnt];

		//process
		//dp는 전역변수로 이미 0으로 채워져 있음
		//0행을 따로 초기화해줄 필요가 없고, 따라서 1행을 별도로 초기화하지 않아도 됨
		//j : 무게 제한 (1부터 K까지 value 합을 반영해주기 위함)
		for (int j = 1; j <= K; j++)
			//해당 무게가 무게 제한을 넘을 경우, Value를 추가하지 못하기 때문에 이전 value를 가져온다
			if (W > j) dp[cnt][j] = dp[cnt - 1][j];
			//무게 제한 j가 물건 무게 W보다 클 경우, 이전 value와 해당 물건이 추가됐을 때 그리고 이전 value 중 큰 것을 선택(DP)
			else dp[cnt][j] = max(dp[cnt - 1][j], dp[cnt - 1][j - W] + V);
		
		cnt++;
	}

	printf("%lld", dp[N][K]);

	return 0;
}