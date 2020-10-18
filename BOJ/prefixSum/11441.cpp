//11441
#include <bits/stdc++.h>
using namespace std;
#define INF 1000000001
#define MAX 100005
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n; cin >> n;
	vi a(n);
	for (int i = 0; i < n; ++i) cin >> a[i];
	int q; cin >> q;
	vi ps(n + 1, 0);
	for (int i = 1; i <= n; ++i)
		ps[i] = ps[i - 1] + a[i - 1];
	while (q--) {
		int a, b; cin >> a >> b;
		cout << ps[b] - ps[a - 1] << '\n';
	}

	return 0;
}