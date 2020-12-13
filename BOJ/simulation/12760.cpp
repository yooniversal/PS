//12760
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
const int MAX = 10000001, INF = 1000000001, MOD = 1234567;

int c[101][101], score[101];

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m; cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) cin >> c[i][j];
		sort(c[i], c[i] + m);
	}
	for (int i = 0; i < m; ++i) {
		int maxx = 0;
		for (int j = 0; j < n; ++j)
			maxx = max(maxx, c[j][i]);
		for (int j = 0; j < n; ++j)
			if (maxx == c[j][i])
				++score[j];
	}

	vi ret;
	int maxx = 0;
	for (int i = 0; i < n; ++i) maxx = max(maxx, score[i]);
	for (int i = 0; i < n; ++i) if (maxx == score[i]) ret.push_back(i+1);
	for (int r : ret) cout << r << ' ';
	cout << '\n';

	return 0;
}