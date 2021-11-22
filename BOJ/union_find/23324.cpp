//23324
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
const int MAX = 100005, INF = 1000000001, MOD = 9901;

int uni[MAX];

int find(int a) {
	if (uni[a] == a) return a;
	return uni[a] = find(uni[a]);
}

void make_union(int a, int b) {
	a = find(a), b = find(b);
	if (a <= b) uni[b] = a;
	else uni[a] = b;
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m, k; cin >> n >> m >> k;
	for (int i = 1; i <= n; ++i) uni[i] = i;

	for (int i = 0; i < m; ++i) {
		int u, v; cin >> u >> v;
		if (i == k - 1) continue;
		make_union(u, v);
	}

	int cnt = 0, cnt2 = 0;
	for (int i = 1; i <= n; ++i) {
		if (find(i) == find(1)) ++cnt;
		else ++cnt2;
	}

	cout << 1LL * cnt * cnt2 << '\n';
	
	return 0;
}