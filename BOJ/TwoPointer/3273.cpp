//3273
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
const int MAX = 100005, INF = 1000000001, MOD = 9901;

int n, x;
int cnt[1000001];

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n;
	vi a;
	for (int i = 0; i < n; ++i) {
		int v; cin >> v;
		if (cnt[v] == 0) {
			a.emplace_back(v);
			
		}
		++cnt[v];
	}
	sort(a.begin(), a.end());
	cin >> x;

	int i = 0, j = a.size()-1, ret = 0;
	while (i < j) {
		if (a[i] + a[j] == x) ret += cnt[a[i]] * cnt[a[j]];
		if (a[i] + a[j] <= x) ++i;
		else --j;
	}
	cout << ret << '\n';

	return 0;
}