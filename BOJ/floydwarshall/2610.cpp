//2610
#include <bits/stdc++.h>
using namespace std;
#define INF 1000000000
#define MAX 4000005
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

int d[105][105];
int uni[105];
bool chk[105];
vi u[105];

int find(int a) {
	if (a == uni[a]) return a;
	return uni[a] = find(uni[a]);
}

void make_union(int a, int b) {
	int pa = find(a), pb = find(b);
	if (pa < pb) uni[b] = pa;
	else uni[a] = pb;
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	for (int i = 0; i < 105; ++i)
		for (int j = 0; j < 105; ++j)
			if (i != j)
				d[i][j] = INF;

	for (int i = 0; i < 105; ++i) uni[i] = i;

	int n, m; cin >> n >> m;
	while (m--) {
		int a, b; cin >> a >> b;
		d[a][b] = 1;
		d[b][a] = 1;
	}

	for (int k = 1; k <= n; ++k) {
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				if (d[i][j] > d[i][k] + d[k][j])
					d[i][j] = d[i][k] + d[k][j];
			}
		}
	}

	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			if (i != j && d[i][j] != INF)
				make_union(i, j);

	vi ulist;
	for (int i = 1; i <= n; ++i) {
		u[find(i)].push_back(i);
		ulist.push_back(find(i));
	}
	sort(ulist.begin(), ulist.end());
	ulist.erase(unique(ulist.begin(), ulist.end()), ulist.end());
	
	vi ret;
	cout << ulist.size() << '\n';
	for (int i = 0; i < ulist.size(); ++i) {
		int retlead = -1;
		int retdist = INF;
		for (int j = 0; j < u[ulist[i]].size(); ++j) {
			int leader = u[ulist[i]][j];
			int maxdist = 0;
			for (int k = 0; k < u[ulist[i]].size(); ++k) {
				int member = u[ulist[i]][k];
				maxdist = max(maxdist, d[member][leader]);
			}
			if (retdist > maxdist) {
				retdist = maxdist;
				retlead = leader;
			}
		}
		ret.push_back(retlead);
	}
	sort(ret.begin(), ret.end());
	for (int r : ret) cout << r << '\n';

	return 0;
}