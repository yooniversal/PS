//16987
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
const int MAX = 100001, INF = 1000000001, MOD = 1000000007;

int shield[9], weight[9], ret;
int n;

void DFS(int cur, int cnt) {
	ret = max(ret, cnt);
	if (cur >= n) return;
	if (shield[cur] <= 0) {
		DFS(cur + 1, cnt);
		return;
	}

	for (int next = 0; next < n; ++next) {
		if (shield[next] <= 0 || next == cur) continue;
		shield[cur] -= weight[next];
		shield[next] -= weight[cur];
		int nextCnt = cnt;
		if (shield[cur] <= 0) ++nextCnt;
		if (shield[next] <= 0) ++nextCnt;
		DFS(cur + 1, nextCnt);
		shield[cur] += weight[next];
		shield[next] += weight[cur];
	}
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> shield[i] >> weight[i];
	DFS(0, 0);
	cout << ret << '\n';

	return 0;
}