#include <bits/stdc++.h>
using namespace std;
#define INF 1000000001
#define MAX 300005
#define MOD 1000000007
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int t; cin >> t;
	while (t--) {
		int n, k; cin >> n >> k;
		vi a(n);
		for (int i = 0; i < n; ++i) cin >> a[i];
		int sum = a[0], ret = 0;
		for (int i = 1; i < n; ++i) {
			if (a[i] * 100 > sum * k) {
				int add = (a[i] * 100 - sum*k)/k;
				if ((a[i] * 100 - sum*k) % k != 0) ++add;
				ret += add;
				sum += add;
			}
			sum += a[i];
		}
		cout << ret << '\n';
	}

	return 0;
}