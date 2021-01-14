//16971
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
const int MAX = 100001, INF = 1000000001, MOD = 1234567;

int n, m;
int a[1001][1001], R[1001], ret, tmp;

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> a[i][j];
			if (j == 0 || j == m - 1) R[i] += a[i][j];
			else R[i] += 2 * a[i][j];
		}
		tmp += 2*R[i];
	}
	ret = tmp - R[0] - R[n - 1]; //±âº»°ª

	for (int i : {0, n - 1}) {
		for (int j = 0; j < n; ++j) {
			if (i == j) continue;
			ret = max(ret, tmp - R[i] - R[j]);
		}
	}
	
	for (int i = 1; i < m-1; ++i) {
		for (int j : {0, m - 1}) {
			int mid = 0;
			for (int k = 0; k < n; ++k) {
				if (k == 0 || k == n - 1) mid += R[k] - a[k][i] + a[k][j];
				else mid += 2*R[k] - 2 * a[k][i] + 2 * a[k][j];
			}
			ret = max(ret, mid);
		}
	}

	cout << ret << '\n';

	return 0;
}