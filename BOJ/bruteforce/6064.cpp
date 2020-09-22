//6064
#include <bits/stdc++.h>
using namespace std;
#define INF 1000000001
#define MAX 40001
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

bool chk[MAX];

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int t; cin >> t;
	while (t--) {
		memset(chk, 0, sizeof(chk));
		int M, N, x, y; cin >> M >> N >> x >> y;
		int ret = x;
		bool fin = false;
		while (1) {
			if (N != y && ret % N == y) break;
			if (N == y && ret % y == 0) break;
			if (chk[ret % N]) {
				fin = true;
				break;
			}
			chk[ret % N] = true;

			ret += M;
		}
		if (fin) cout << -1 << '\n';
		else cout << ret << '\n';
	}

	return 0;
}