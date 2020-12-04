//2637
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
const int MAX = 501, INF = 1000000001, MOD = 1000000007;

int cache[101][101], n;
bool notBase[101];
vii adj[101];

//a번 제품을 만들 때 필요한 재료 b의 갯수
int f(int a, int b) {
	if (a == b) return 1;
	int& ret = cache[a][b];
	if (ret != -1) return ret;
	ret = 0;
	for (auto& next : adj[a]) {
		ret += f(next.first, b) * next.second;
	}
	return ret;
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	memset(cache, -1, sizeof(cache));
	int m; cin >> n >> m;
	while (m--) {
		int x, y, k; cin >> x >> y >> k;
		notBase[x] = true;
		adj[x].push_back({ y, k });
	}

	for (int i = 1; i < n; ++i) {
		if (notBase[i]) continue;
		cout << i << ' ' << f(n, i) << '\n';
	}

	return 0;
}