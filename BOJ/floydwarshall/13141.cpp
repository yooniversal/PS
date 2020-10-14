//13141
#include <bits/stdc++.h>
using namespace std;
#define INF 1000000001
#define MAX 100005
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

int n, m;

double solve(int cur, vvi d, vvi maxd) {
	int tmp = 0;
	for (int next = 1; next <= n; ++next)
		tmp = max(tmp, d[cur][next]);
	for (int next = 1; next <= n; ++next) {
		maxd[cur][next] -= tmp;
		maxd[next][cur] -= tmp;
		if (d[cur][next] - tmp < 0) {
			int diff = tmp - d[cur][next];
			if (maxd[cur][next] > 0) maxd[cur][next] -= diff;
			if (maxd[next][cur] > 0) maxd[next][cur] -= diff;
			for (int adj = 1; adj <= n; ++adj) {
				maxd[next][adj] -= diff;
				maxd[adj][next] -= diff;
			}
		}
	}
	double maxx = 0;
	for (int c = 1; c <= n; ++c) {
		for (int next = c; next <= n; ++next) {
			maxx = max(maxx, (double)maxd[c][next]);
		}
	}
	return maxx / 2.0 + tmp;
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	vvi d(201, vector<int>(201, 0));
	vvi maxd(201, vector<int>(201, 0));
	for (int i = 0; i < 201; ++i)
		for (int j = 0; j < 201; ++j)
			if (i != j)
				d[i][j] = INF;

	cin >> n >> m;
	while (m--) {
		int a, b, l; cin >> a >> b >> l;
		d[a][b] = min(d[a][b], l);
		d[b][a] = min(d[b][a], l);
		maxd[a][b] = max(maxd[a][b], l);
		maxd[b][a] = max(maxd[b][a], l);
	}

	for (int k = 1; k <= n; ++k)
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= n; ++j)
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);

	double ret = 987654321.0;
	for (int cur = 1; cur <= n; ++cur) {
		ret = min(ret, solve(cur, d, maxd));
	}
	printf("%.1lf", ret);

	return 0;
}