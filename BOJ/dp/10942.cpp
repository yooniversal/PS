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

//���ǰ� return�� ������ ����ؼ� DP �����ϱ�
//DP[n][m]�� n~m��°�� �Ӹ�������� ��Ÿ��
int dpf(int n, int m) {
	//n=m �̸� ���ڰ� 1���̹Ƿ� �Ӹ����
	if (n >= m) return dp[n][m] = 1;
	//�⺻���� -1, ������� ��� �� ��ȯ
	if (dp[n][m] != -1) return dp[n][m];
	//�� ���ڰ� �ٸ��� �翬�� �Ӹ����X ->�ٷ� 0 ����
	if (arr[n] != arr[m]) return dp[n][m] = 0;
	else {
		//�� ���ڴ� ������ + �� ������ ���빰�� �Ӹ������ �ƴϸ� -> X
		if (dpf(n + 1, m - 1) == 0) return dp[n][m] = 0;
	}
	//��� ������ ����ϹǷ� �Ӹ����
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

	//DP ���̺� Ȱ���� ���� -1�� �ʱ�ȭ ���ֱ�
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