//1068
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
const int MAX = 200005, INF = 1000000001, MOD = 9901;

int n, ban, ret;
vi adj[51];

void DFS(int cur) {
	if (adj[cur].size() == 0) {
		++ret;
		return;
	}

	bool flag = true;
	for (auto& next : adj[cur]) {
		if (ban == next) continue;
		DFS(next);
		flag = false;
	}
	if (flag) ++ret;
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n;
	int root = -1;
	for (int i = 0; i < n; ++i) {
		int p; cin >> p;
		if (p == -1) {
			root = i;
			continue;
		}
		adj[p].push_back(i);
	}
	cin >> ban;

	if (ban != root) DFS(root);
	cout << ret << '\n';

	return 0;
}