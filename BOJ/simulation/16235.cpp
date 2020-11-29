//16235
#include <bits/stdc++.h>
using namespace std;
#define INF 1000000001
#define MAX 80
#define MOD 1000000007
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

int dx[] = { -1,-1,-1,0,0,1,1,1 }, dy[] = { -1,0,1,-1,1,-1,0,1 };
int land[11][11], a[11][11];
vi tree[11][11];
int n, m, k;

bool OOB(int x, int y) { return x < 1 || x >= n+1 || y < 1 || y >= n+1; }

void year() {
	//봄 & 여름
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j) {
			if (tree[i][j].size() == 0) continue;
			sort(tree[i][j].begin(), tree[i][j].end());
			int remain = land[i][j];
			land[i][j] = 0;
			int deadPoint = -1;
			for (int t = 0; t < tree[i][j].size(); ++t) {
				if (remain < tree[i][j][t]) {
					land[i][j] += tree[i][j][t] / 2;
					if (deadPoint == -1) deadPoint = t;
				}
				else {
					remain -= tree[i][j][t];
					++tree[i][j][t];
				}
			}
			land[i][j] += remain;
			if(deadPoint != -1) tree[i][j].erase(tree[i][j].begin() + deadPoint, tree[i][j].end());
		}

	//가을 & 겨울
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j) {
			land[i][j] += a[i][j];
			for (int t = 0; t < tree[i][j].size(); ++t) {
				if (tree[i][j][t] % 5 == 0) {
					for (int d = 0; d < 8; ++d) {
						int nx = i + dx[d], ny = j + dy[d];
						if (OOB(nx, ny)) continue;
						tree[nx][ny].push_back(1);
					}
				}
			}
		}
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n >> m >> k;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			cin >> a[i][j];
			land[i][j] = 5;
		}
	}
	while (m--) {
		int x, y, old; cin >> x >> y >> old;
		tree[x][y].push_back(old);
	}

	for (int i = 0; i < k; ++i) {
		year();
	}

	int ret = 0;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			ret += tree[i][j].size();
	cout << ret << '\n';

	return 0;
}