#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <cmath>
#include <algorithm>
#include <map>
using namespace std;
#define INF 987654321
#define MAX 201
typedef long long ll;

ll dp[MAX][MAX][MAX];

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int r, g, b; cin >> r >> g >> b;
	vector<ll> rv(r), gv(g), bv(b);

	for (int i = 0; i < r; i++) cin >> rv[i];
	for (int i = 0; i < g; i++) cin >> gv[i];
	for (int i = 0; i < b; i++) cin >> bv[i];

	sort(rv.begin(), rv.end());
	sort(gv.begin(), gv.end());
	sort(bv.begin(), bv.end());

	for (int i = 0; i <= r; i++) {
		for (int j = 0; j <= g; j++) {
			for (int k = 0; k <= b; k++) {
				if(i>0&&j>0) dp[i][j][k] = max(dp[i][j][k], dp[i-1][j-1][k] + rv[i-1]*gv[j-1]);
				if(i>0&&k>0) dp[i][j][k] = max(dp[i][j][k], dp[i-1][j][k-1] + rv[i-1]*bv[k-1]);
				if(j>0&&k>0) dp[i][j][k] = max(dp[i][j][k], dp[i][j-1][k-1] + gv[j-1]*bv[k-1]);
			}
		}
	}

	cout << dp[r][g][b];
	
	return 0;
}