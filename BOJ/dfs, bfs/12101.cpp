//12101
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
const int MAX = 100001, INF = 1000000001, MOD = 1000000007;

int n, k;
vi ret;

void DFS(int cur){
	if (cur > n) return;
	if (cur == n) {
		if (k == 0) {
			for (int i = 0; i < ret.size(); ++i) {
				if (i == ret.size() - 1) cout << ret[i];
				else cout << ret[i] << '+';
			}
			cout << '\n';
			exit(0);
		}
		--k;
		return;
	}

	for (int i = 1; i <= 3; ++i) {
		ret.push_back(i);
		DFS(cur + i);
		ret.pop_back();
	}
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n >> k;
	--k;
	DFS(0);
	cout << -1 << '\n';

	return 0;
}