//2960
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
const int MAX = 100005, INF = 1000000001, MOD = 1234567;

bool p[1001];

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	memset(p, 1, sizeof(p));
	int n, k, cnt = 0; cin >> n >> k;
	for (int i = 2; i <= n; ++i) {
		if (!p[i]) continue;
		for (int j = i; j <= n; j += i) {
			if (!p[j]) continue;
			p[j] = false;
			if (++cnt == k) {
				cout << j << '\n';
				return 0;
			}
		}
	}

	return 0;
}