//18243
#include <bits/stdc++.h>
using namespace std;
#define INF 1000000007
#define MAX 50001
#define MOD 1000000000
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

int d[101][101];
int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	for (int i = 0; i < 101; ++i)
		for (int j = 0; j < 101; ++j)
			if (i != j)
				d[i][j] = INF;
	
	int n, k; cin >> n >> k;
	while (k--) {
		int a, b; cin >> a >> b;
		d[a][b] = 1;
		d[b][a] = 1;
	}

	for (int k = 1; k <= n; ++k)
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= n; ++j)
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);

	for(int i=1; i<=n; ++i)
		for(int j=1; j<=n; ++j)
			if (d[i][j] > 6) {
				cout << "Big World!";
				return 0;
			}

	cout << "Small World!";

	return 0;
}