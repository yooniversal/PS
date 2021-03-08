//11728
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
const int MAX = 100005, INF = 1000000001, MOD = 9901;

int n, m;
vi a, b;

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n >> m;
	a.resize(n, 0);
	b.resize(m, 0);

	for (int i = 0; i < n; ++i) cin >> a[i];
	for (int i = 0; i < m; ++i) cin >> b[i];
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());

	int l = 0, r = 0;
	while (l != n || r != m) {
		if (l < n) {
			if (r < m) {
				if (a[l] < b[r]) cout << a[l++] << ' ';
				else cout << b[r++] << ' ';
			}
			else 
				while (l < n) cout << a[l++] << ' ';
		}
		else {
			while (r < m) cout << b[r++] << ' ';
		}
	}
	cout << '\n';

	return 0;
}