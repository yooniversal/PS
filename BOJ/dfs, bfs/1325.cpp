//1325
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
const int MAX = 10005, INF = 1000000001, MOD = 9901;

int n, m, cnt[MAX], connect;
bool chk[MAX];
vi adj[MAX];

void DFS(int cur) {

	++connect;

	for (auto& next : adj[cur]) {
		if (chk[next]) continue;
		chk[next] = true;
		DFS(next);
	}

}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n >> m;
	while (m--) {
		int u, v; cin >> u >> v;
		adj[v].push_back(u);
	}

	int maxx = 0;
	for (int i = 1; i <= n; ++i) {

		memset(chk, false, sizeof(chk));
		chk[i] = true;
		connect = -1;
		DFS(i);
		cnt[i] = connect;

		maxx = max(maxx, cnt[i]);
	}

	vi ret;
	for (int i = 1; i <= n; ++i) {
		if (cnt[i] == maxx) ret.push_back(i);
	}

	for (auto& r : ret)
		cout << r << ' ';
	cout << '\n';

	return 0;
}