#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
#define MAX 1001
typedef long long ll;

int a[MAX];

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int t; cin >> t;
	while (t--) {
		int n, x; cin >> n >> x;
		int cnt = 0;
		int sum = 0;
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
			if (a[i] == x) cnt++;
			sum += a[i] - x;
		}
		if (cnt == n) cout << 0 << '\n';
		else if (cnt > 0) cout << 1 << '\n';
		else if (sum == 0) cout << 1 << '\n';
		else cout << 2 << '\n';
	}

	return 0;
}