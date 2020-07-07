//11660

#include <iostream>
using namespace std;

int dp[1024*1024+1];

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N, M;
	int tmp;
	cin >> N >> M;

	for (int i = 1; i <= N * N; i++) {
		cin >> tmp;
		dp[i] = dp[i - 1] + tmp;
	}

	while (M--) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		int ans = 0;
		for (int i = a; i <= c; i++)
			ans += dp[(i - 1) * N + d] - dp[(i - 1) * N + b - 1];
		cout << ans << '\n';
	}

	return 0;
}