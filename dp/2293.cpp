//2293

#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int dp[10001], coin[101];

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, k;
	cin >> n >> k;

	dp[0] = 1;
	
	for (int i = 0; i < n; i++)
		cin >> coin[i];

	sort(coin, coin+n);

	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= k; j++) {
			if (coin[i - 1] <= j) dp[j] += dp[j - coin[i - 1]];
		}
	}

	/*for (int j = 0; j <= k; j++)
		cout << dp[j] << " ";
	cout << endl;*/

	cout << dp[k];

	return 0;
}