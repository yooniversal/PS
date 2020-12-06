//12849
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
const int MAX = 100001, INF = 1000000001, MOD = 1000000007;

bool adj[9][9];
int cache[100001][9];

int f(int remain, int cur) {
	if (remain == 0) {
		if (cur == 1) return 1;
		return 0;
	}
	int& ret = cache[remain][cur];
	if (ret != -1) return ret;
	ret = 0;
	for (int i = 1; i <= 8; ++i) 
		if(adj[cur][i]) ret = (ret + f(remain - 1, i)) % MOD;
	return ret;
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	adj[1][2] = adj[1][3] = 1;
	adj[2][1] = adj[2][3] = adj[2][4] = 1;
	adj[3][1] = adj[3][2] = adj[3][4] = adj[3][6] = 1;
	adj[4][2] = adj[4][3] = adj[4][5] = adj[4][6] = 1;
	adj[5][4] = adj[5][6] = adj[5][7] = 1;
	adj[6][3] = adj[6][4] = adj[6][5] = adj[6][8] = 1;
	adj[7][5] = adj[7][8] = 1;
	adj[8][6] = adj[8][7] = 1;

	memset(cache, -1, sizeof(cache));
	int d; cin >> d;
	cout << f(d, 1) << '\n';

	return 0;
}