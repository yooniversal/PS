//3075
#include <bits/stdc++.h>
using namespace std;
#define INF 1000000001
#define MAX 100005
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

ll d[101][101];

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int t; cin >> t;
	while (t--) {
		for (int i = 0; i < 101; ++i)
			for (int j = 0; j < 101; ++j)
				if (i != j)
					d[i][j] = INF;

		int n, p, q; cin >> n >> p >> q;
		vi people(n);
		for (int i = 0; i < n; ++i) cin >> people[i];
		while (q--) {
			int s, e, dist; cin >> s >> e >> dist;
			d[s][e] = min(d[s][e], (ll)dist);
			d[e][s] = min(d[e][s], (ll)dist);
		}

		for (int k = 1; k <= p; ++k)
			for (int i = 1; i <= p; ++i)
				for (int j = 1; j <= p; ++j)
					if(d[i][j] > d[i][k] + d[k][j])
						d[i][j] = d[i][k] + d[k][j];

		pair<int, ll> ret = { 0, 1e14 };
		for (int arrive = 1; arrive <= p; ++arrive) {
			ll distSum = 0;
			bool flag = false;
			for (int i = 0; i < n; ++i) {
				if (d[people[i]][arrive] == INF) flag = true;
				distSum += d[people[i]][arrive] * d[people[i]][arrive];
			}
			if (flag) continue;
			if (ret.second > distSum) {
				ret.first = arrive;
				ret.second = distSum;
			}
		}
		cout << ret.first << " " << ret.second << '\n';
	}

	return 0;
}