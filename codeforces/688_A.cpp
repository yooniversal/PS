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

bool chk[101];

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int t; cin >> t;
	while (t--) {
		memset(chk, 0, sizeof(chk));
		int n, m; cin >> n >> m;
		for (int i = 0; i < n; ++i) {
			int x; cin >> x;
			chk[x] = true;
		}
		int ret = 0;
		for (int i = 0; i < m; ++i) {
			int x; cin >> x;
			if (chk[x]) ++ret;
		}
		cout << ret << '\n';
	}

	return 0;
}