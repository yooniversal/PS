//1855
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
const int MAX = 5005, INF = 1000000001, MOD = 1234567;

char a[201][21];

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int k; string s; cin >> k >> s;
	for (int i = 0, d = 0; i < s.size() / k; ++i, d = !d) {
		if (d == 0) {
			for (int c = 0; c < k; ++c)
				a[i][c] = s[i * k + c];
		}
		else {
			for (int c = 0, rc = k - 1; c < k && rc >= 0; ++c, --rc)
				a[i][rc] = s[i * k + c];
		}
	}

	string ret;
	for (int i = 0; i < k; ++i)
		for (int j = 0; j < s.size() / k; ++j)
			ret += a[j][i];
	cout << ret << '\n';

	return 0;
}