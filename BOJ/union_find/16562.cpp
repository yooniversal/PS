//16562
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
const int MAX = 10001, INF = 1000000001, MOD = 1234567;

int price[MAX], uni[MAX], cost[MAX];
bool chk[MAX];

int find(int a) {
	if (uni[a] == a) return a;
	return uni[a] = find(uni[a]);
}

void makeUnion(int a, int b) {
	a = find(a), b = find(b);
	if (a < b) uni[a] = b;
	else uni[b] = a;
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	for (int i = 0; i < MAX; ++i) uni[i] = i;
	int n, m, k; cin >> n >> m >> k;
	for (int i = 1; i <= n; ++i) cin >> price[i];
	while (m--) {
		int u, v; cin >> u >> v;
		makeUnion(u, v);
	}

	fill(cost + 1, cost + 1 + n, INF);
	for (int i = 1; i <= n; ++i) cost[find(i)] = min(cost[find(i)], price[i]);
	
	int sum = 0;
	for (int i = 1; i <= n; ++i) {
		if (chk[find(i)]) continue;
		chk[find(i)] = true;
		sum += cost[find(i)];
	}
	if (k < sum) cout << "Oh no\n";
	else cout << sum << '\n';

	return 0;
}