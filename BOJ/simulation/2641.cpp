//2641
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
const int MAX = 1001, INF = 1000000001, MOD = 1000000007;

int dx[] = { 0,-1,0,1 }, dy[] = { 1,0,-1,0 };

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	while (cin >> n) {
		vii xy;
		int x = 0, y = 0;
		for (int i = 0; i < n; ++i) {
			int d; cin >> d;
			--d;
			x += dx[d], y += dy[d];
			xy.push_back({ x, y });
		}
		sort(xy.begin(), xy.end());
		int addx = -xy[0].first, addy = -xy[0].second;
		for (int i = 0; i < xy.size(); ++i)
			xy[i].first += addx, xy[i].second += addy;

		int k; cin >> k;
		vvi ret;
		for (int i = 0; i < k; ++i) {
			vii tmp; vi now;
			int tx = 0, ty = 0;
			for (int j = 0; j < n; ++j) {
				int d; cin >> d;
				now.push_back(d);
				--d;
				tx += dx[d], ty += dy[d];
				tmp.push_back({ tx, ty });
			}
			sort(tmp.begin(), tmp.end());
			int addx = -tmp[0].first, addy = -tmp[0].second;
			for (int it = 0; it < tmp.size(); ++it)
				tmp[it].first += addx, tmp[it].second += addy;

			bool flag = true;
			for(int it = 0; it<n; ++it)
				if (xy[it].first != tmp[it].first || xy[it].second != tmp[it].second) {
					flag = false;
					break;
				}
			if (flag) ret.push_back(now);
		}

		cout << ret.size() << '\n';
		for (int i = 0; i < ret.size(); ++i) {
			for (int d : ret[i]) cout << d << ' ';
			cout << '\n';
		}
	}

	return 0;
}