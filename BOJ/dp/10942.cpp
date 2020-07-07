//10942

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

int dp[2001][2001], arr[2001];

//조건과 return을 적절히 사용해서 DP 진행하기
//DP[n][m]은 n~m번째가 팰린드롬인지 나타냄
int dpf(int n, int m) {
	//n=m 이면 문자가 1개이므로 팰린드롬
	if (n >= m) return dp[n][m] = 1;
	//기본값은 -1, 변경됐을 경우 값 반환
	if (dp[n][m] != -1) return dp[n][m];
	//끝 글자가 다르면 당연히 팰린드롬X ->바로 0 리턴
	if (arr[n] != arr[m]) return dp[n][m] = 0;
	else {
		//끝 글자는 같지만 + 그 사이의 내용물이 팰린드롬이 아니면 -> X
		if (dpf(n + 1, m - 1) == 0) return dp[n][m] = 0;
	}
	//모든 조건을 통과하므로 팰린드롬
	return dp[n][m] = 1;
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int l, r, n;

	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> arr[i];

	//DP 테이블 활용을 위해 -1로 초기화 해주기
	memset(dp, -1, sizeof(dp));

	int m;
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> l >> r;
		dp[l][r] = dpf(l, r);
		cout << dpf(l, r) << '\n';
	}

	return 0;
}