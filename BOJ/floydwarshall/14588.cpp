//14588
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

struct P {
	int l, r;
};

int d[301][301];
int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	for (int i = 0; i < 301; ++i)
		for (int j = 0; j < 301; ++j)
			if (i != j)
				d[i][j] = INF;

	int n; cin >> n;
	vector<P> person(n+1);
	for (int i = 1; i <= n; ++i)
		cin >> person[i].l >> person[i].r;

	for(int i=1; i<=n; ++i)
		for(int j=1; j<=n; ++j)
			if (i != j) {
				if (person[j].l <= person[i].r && person[i].l <= person[j].r) {
					d[i][j] = 1;
					d[j][i] = 1;
				}
			}

	for (int k = 1; k <= n; ++k)
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= n; ++j)
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);

	int k; cin >> k;
	while (k--) {
		int a, b; cin >> a >> b;
		if (d[a][b] != INF) cout << d[a][b] << '\n';
		else cout << -1 << '\n';
	}

	return 0;
}