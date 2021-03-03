//1783
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
const int MAX = 100005, INF = 1000000001, MOD = 9901;

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m; cin >> n >> m;
	int a[] = { 0,1,2,3,4,4,4 };
	if (n >= 3) {
		if (m <= 6) {
			cout << a[m] << '\n';
		}
		else {
			cout << m - 2 << '\n';
		}
	}
	else {
		if (n == 2) {
			if (m <= 2) cout << 1 << '\n';
			else if (m <= 4) cout << 2 << '\n';
			else if (m <= 6) cout << 3 << '\n';
			else cout << 4 << '\n';
		}
		else cout << 1 << '\n';
	}

	return 0;
}