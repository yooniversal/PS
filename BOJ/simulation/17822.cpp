//17822
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
const int MAX = 100005, INF = 1000000001, MOD = 9901;

int n, m, t;
int c[51][51];

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n >> m >> t;
	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> c[i][j];
		}
	}
	while (t--) {
		int x, d, k; cin >> x >> d >> k;
		
		// 원판 돌리기
		for (int cur = 1; cur <= n; ++cur) {
			if (cur % x) continue;
			vi tmp(m, 0);
			for (int j = 0; j < m; ++j) {
				// 방향을 고려한 다음 위치에 값 넣기
				int next = d == 0 ? (j + k) % m : j - k;
				if (next < 0) next = m + next;
				tmp[next] = c[cur][j];
			}
			// 반영
			for (int j = 0; j < m; ++j)
				c[cur][j] = tmp[j];
		}

		// 인접한 값들과 같은지 체크
		double sum = 0, cnt = 0;
		bool chk[51][51] = { 0, }, flag = false;
		for (int cur = 1; cur <= n; ++cur) {
			for (int j = 0; j < m; ++j) {
				sum += c[cur][j];
				if (c[cur][j]) cnt += 1.0;

				if (c[cur][j] == 0) continue;
				for (int next : {j + 1, j - 1}) {
					if (next >= m) next %= m;
					if (next < 0) next += m;
					if (c[cur][j] == c[cur][next])
						chk[cur][j] = chk[cur][next] = flag = true;
				}
				if (cur - 1 >= 1 && c[cur][j] == c[cur - 1][j])
					chk[cur][j] = chk[cur - 1][j] = flag = true;
				if (cur + 1 <= n && c[cur][j] == c[cur + 1][j])
					chk[cur][j] = chk[cur + 1][j] = flag = true;
			}
		}

		if (flag) {
			for (int i = 1; i <= n; ++i) for (int j = 0; j < m; ++j) {
				if (!chk[i][j]) continue;
				c[i][j] = 0;
			}
		}
		else {
			double v = sum / cnt;
			for (int i = 1; i <= n; ++i) for (int j = 0; j < m; ++j) {
				if (c[i][j] == 0 || c[i][j] == v) continue;
				if (c[i][j] > v) --c[i][j];
				else ++c[i][j];
			}
		}
	}

	int ret = 0;
	for (int i = 1; i <= n; ++i) for (int j = 0; j < m; ++j) {
		ret += c[i][j];
	}
	cout << ret << '\n';

	return 0;
}