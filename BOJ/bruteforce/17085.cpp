//17085
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
const int MAX = 10000001, INF = 1000000001, MOD = 1234567;

int dx[] = { -1,1,0,0 }, dy[] = { 0,0,1,-1 };
int n, m, ret;
vector<string> a;
bool chk[16][16];

bool OOB(ii& xy) {
	int x = xy.first, y = xy.second;
	return x < 0 || x >= n || y < 0 || y >= m;
}

void DFS(int sum, int cnt) {
	if (cnt == 2) {
		ret = max(ret, sum);
		return;
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (a[i][j] == '.' || chk[i][j]) continue;
			int curSize = 1; ii xy[4];
			for (int k = 0; k < 4; ++k) xy[k] = { i,j };
			vii xys;
			xys.push_back({ i,j });
			chk[i][j] = true;
			while (1) {
				DFS(sum * curSize, cnt + 1);
				bool flag = false;
				for (int d = 0; d < 4; ++d) {
					xy[d].first += dx[d], xy[d].second += dy[d];
					if (OOB(xy[d]) || chk[xy[d].first][xy[d].second] || a[xy[d].first][xy[d].second] == '.') {
						flag = true;
						break;
					}
					xys.push_back(xy[d]);
					chk[xy[d].first][xy[d].second] = true;
				}
				if (flag) break;
				curSize += 4;
			}
			for (auto& cur : xys) chk[cur.first][cur.second] = false;
		}
	}
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		string s; cin >> s;
		a.push_back(s);
	}

	DFS(1, 0);
	cout << ret << '\n';

	return 0;
}