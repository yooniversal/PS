//3035
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
const int MAX = 10000001, INF = 1000000001, MOD = 1234567;

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int r, c, zr, zc; cin >> r >> c >> zr >> zc;
	vector<string> a(r);
	for (int i = 0; i < r; ++i) cin >> a[i];
	for (int i = 0; i < r; ++i) {
		string tmp;
		for (int j = 0; j < c; ++j) {
			for (int C = 0; C < zc; ++C) tmp += a[i][j];
		}
		for (int R = 0; R < zr; ++R) cout << tmp << '\n';
	}

	return 0;
}