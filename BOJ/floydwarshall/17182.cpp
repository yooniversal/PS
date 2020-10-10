//17182
#include <bits/stdc++.h>
using namespace std;
#define INF 1000000007
#define MAX 50001
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

int d[11][11];
bool chk[11];
int n, k;
int ret = INF;

void dfs(int cur, int cnt, int dist) {
	if (cnt == n) {
		ret = min(ret, dist);
		return;
	}

	for (int i = 0; i < n; ++i) {
		if (chk[i]) continue;
		chk[i] = true;
		dfs(i, cnt+1, dist + d[cur][i]);
		chk[i] = false;
	}
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n >> k;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			cin >> d[i][j];

	for (int k = 0; k < n; ++k)
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				if (d[i][j] > d[i][k] + d[k][j])
					d[i][j] = d[i][k] + d[k][j];

	chk[k] = true;
	dfs(k, 1, 0);
	cout << ret;

	return 0;
}