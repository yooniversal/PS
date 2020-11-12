//17943
#include <bits/stdc++.h>
using namespace std;
#define INF 1000000001
#define MAX 100001
#define MOD 1000000007
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

int v[MAX]; //i번까지 XOR한 값

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, q; cin >> n >> q;
	for (int i = 2; i <= n; ++i) {
		int x; cin >> x;
		v[i] = v[i - 1] ^ x;
	}
	while (q--) {
		int mode; cin >> mode;
		if (mode == 0) {
			int x, y; cin >> x >> y;
			int ret = v[y] ^ v[x];
			cout << ret << '\n';
		}
		else {
			int x, y, d; cin >> x >> y >> d;
			int ret = v[y] ^ v[x];
			ret ^= d;
			cout << ret << '\n';
		}
	}

	return 0;
}