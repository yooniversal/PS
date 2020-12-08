//16922
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
const int MAX = 1001, INF = 1000000001, MOD = 100000;

int n, val[4] = { 1, 5, 10, 50 };
bool chk[1001][21], retchk[1001];

void DFS(int cur, int remain) {
	if (remain == 0) {
		retchk[cur] = true;
		return;
	}
	for (int i = 0; i < 4; ++i) {
		if (chk[cur + val[i]][remain]) continue;
		chk[cur + val[i]][remain] = true;
		if(remain > 0) DFS(cur + val[i], remain-1);
	}
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n;
	DFS(0, n);
	int ret = 0;
	for (int i = 0; i < 1001; ++i)
		if (retchk[i]) ++ret;
	cout << ret << '\n';

	return 0;
}