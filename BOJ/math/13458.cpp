//13458
#include <bits/stdc++.h>
using namespace std;
#define INF 1000000000
#define MAX 10001
#define MOD 10007
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, b, c; cin >> n;
	vi a(n);
	for (int i = 0; i < n; ++i) cin >> a[i];
	cin >> b >> c;

	int ret = 0;
	for (int i = 0; i < n; ++i) {
		if (a[i] <= b) ++ret;
		else {
			ret += (a[i] - b) / c + 1;
			if ((a[i] - b) % c != 0) ++ret;
		}
	}
	cout << ret;

	return 0;
}