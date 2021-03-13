//17140
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
const int MAX = 100005, INF = 1000000001, MOD = 9901;

int r, c, k;

void solve(const vvi& a, int cnt) {
	int n = a.size(), m = a[0].size(), mmax = 0;
	//printf("%d<=%d %d<=%d\n", r, n - 1, c, m - 1);
	if (((r<=n-1&&c<=m-1) && a[r][c] == k) || cnt > 100) {
		if (cnt > 100) cout << -1 << '\n';
		else cout << cnt << '\n';
		exit(0);
	}

	//printf("n:%d m:%d\n", n, m);
	vvi ret;
	// R연산
	if (n >= m) {
		for (int i = 0; i < n; ++i) {
			int idx[101];
			fill(idx, idx + 101, -1);
			vii tmp;
			for (int j = 0; j < m; ++j) {
				if (a[i][j] == 0) continue;
				if (idx[a[i][j]] == -1) {
					idx[a[i][j]] = tmp.size();
					tmp.push_back({ 1, a[i][j] });
				}
				else {
					tmp[idx[a[i][j]]].first += 1;
				}
			}
			mmax = max(mmax, (int)tmp.size() * 2);
			sort(tmp.begin(), tmp.end());
			vi input;
			for (auto& t : tmp) {
				input.emplace_back(t.second);
				input.emplace_back(t.first);
			}
			ret.emplace_back(input);
		}

		for (int i = 0; i < n; ++i)
			while (ret[i].size() < mmax)
				ret[i].emplace_back(0);
	}
	// C연산
	else {
		vvi before;
		for (int i = 0; i < m; ++i) {
			int idx[101];
			fill(idx, idx + 101, -1);
			vii tmp;
			for (int j = 0; j < n; ++j) {
				if (a[j][i] == 0) continue;
				if (idx[a[j][i]] == -1) {
					idx[a[j][i]] = tmp.size();
					tmp.push_back({ 1, a[j][i] });
				}
				else {
					tmp[idx[a[j][i]]].first += 1;
				}
			}
			mmax = max(mmax, (int)tmp.size() * 2);	
			sort(tmp.begin(), tmp.end());
			vi input;
			for (auto& t : tmp) {
				input.emplace_back(t.second);
				input.emplace_back(t.first);
			}
			before.emplace_back(input);
		}

		for (int i = 0; i < m; ++i)
			while (before[i].size() < mmax)
				before[i].emplace_back(0);

		ret.resize(before[0].size(), vi(before.size()));
		for (int i = 0; i < before.size(); ++i)
			for (int j = 0; j < before[0].size(); ++j)
				ret[j][i] = before[i][j];
	}

	/*printf("처리된 상태 ~ cnt:%d\n", cnt);
	for (int i = 0; i < ret.size(); ++i) {
		for (int j = 0; j < ret[0].size(); ++j)
			cout << ret[i][j] << ' ';
		cout << '\n';
	}
	cout << "--------------\n";*/
	
	solve(ret, cnt + 1);
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> r >> c >> k;
	--r, --c;
	vvi a(3, vi(3, 0));
	for (int i = 0; i < 3; ++i) for (int j = 0; j < 3; ++j) cin >> a[i][j];

	solve(a, 0);

	return 0;
}