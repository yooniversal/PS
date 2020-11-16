//17218
#include <bits/stdc++.h>
using namespace std;
#define INF 1000000001
#define MAX 4005
#define MOD 1000000000
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

struct P {
	int x, y;
	string s;
};

int dp[45][45];
ii route[45][45];

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	string s1, s2; cin >> s1 >> s2;
	if (s1.size() < s2.size()) swap(s1, s2);

	for (int i = 0; i < s1.size(); ++i) {
		for (int j = 0; j < s2.size(); ++j) {
			if (s1[i] == s2[j]) {
				dp[i + 1][j + 1] = dp[i][j] + 1;
				route[i + 1][j + 1] = { i, j };
			}
			else {
				if (dp[i + 1][j] <= dp[i][j + 1]) {
					dp[i + 1][j + 1] = dp[i][j + 1];
					route[i + 1][j + 1] = { i, j + 1 };
				}
				else {
					dp[i + 1][j + 1] = dp[i + 1][j];
					route[i + 1][j + 1] = { i + 1, j };
				}
			}
		}
	}

	string ret = "";
	for (int x = s1.size(), y = s2.size(); dp[x][y] != 0; ) {
		int nx = route[x][y].first, ny = route[x][y].second;
		if (nx == x - 1 && ny == y - 1) ret += s1[x - 1];
		x = nx; y = ny;
	}
	
	reverse(ret.begin(), ret.end());
	cout << ret;

	return 0;
}