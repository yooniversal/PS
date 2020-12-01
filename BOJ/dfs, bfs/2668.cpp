//2668
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
const int MAX = 100001, INF = 1000000001, MOD = 1000000007;

int n;
int num[101];
bool chk[101], ans[101];

bool DFS(int start, int cur) {
	if (ans[cur]) return false;
	if (start == num[cur]) {
		ans[cur] = chk[cur] = true;
		return true;
	}
	if (chk[cur]) return false;
	chk[cur] = true;
	if (DFS(start, num[cur])) {
		ans[cur] = true;
		return true;
	}
	return false;
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n;
	for (int i = 1; i <= n; ++i) cin >> num[i];

	int ret = 0;
	for (int i = 1; i <= n; ++i) {
		memset(chk, false, sizeof(chk));
		DFS(i, i);
	}

	vi R;
	for (int i = 1; i <= n; ++i) {
		if (ans[i]) {
			R.push_back(i);
			++ret;
		}
	}
	cout << ret << '\n';
	for (int RR : R) cout << RR << '\n';

	return 0;
}