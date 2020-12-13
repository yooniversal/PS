//11376
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
const int MAX = 1005, INF = 1000000001, MOD = 1234567;

vi person[MAX];
bool chk[MAX];
int from[MAX];

bool dfs(int cur) {
	for (auto& next : person[cur]) {
		if (chk[next]) continue;
		chk[next] = true;

		if (from[next] == 0 || dfs(from[next])) {
			from[next] = cur;
			return true;
		}
	}
	return false;
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m; cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		int work; cin >> work;
		for (int j = 0; j < work; j++) {
			int next; cin >> next;
			person[i].push_back(next);
		}
	}

	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		memset(chk, 0, sizeof(chk));
		if (dfs(i)) cnt++;
		memset(chk, 0, sizeof(chk));
		if (dfs(i)) cnt++;
	}
	cout << cnt << '\n';

	return 0;
}