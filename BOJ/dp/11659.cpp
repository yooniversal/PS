//11659

#include <iostream>
using namespace std;

int dp[100001];

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N, M;
	int tmp;
	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		cin >> tmp;
		dp[i] = dp[i - 1] + tmp;
	}

	while (M--) {
		int a, b;
		cin >> a >> b;
		cout << dp[b] - dp[a - 1] << '\n';
	}

	return 0;
}