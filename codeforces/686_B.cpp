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

int chk[200001];
int idx[200001];

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int t; cin >> t;
	while (t--) {
		memset(chk, 0, sizeof(chk));
		memset(idx, 0, sizeof(idx));
		int n; cin >> n;
		vi a(n);
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
			++chk[a[i]];
			idx[a[i]] = i + 1;
		}
		int ret = INF;
		for (int i = 1; i <= n; ++i) {
			if (chk[i] > 1 || chk[i] == 0) continue;
			ret = idx[i];
			break;
		}
		if (ret == INF) cout << -1 << '\n';
		else cout << ret << '\n';
	}

	return 0;
}