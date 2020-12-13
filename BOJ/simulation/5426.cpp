//5426
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

	int t; cin >> t;
	while (t--) {
		string s; cin >> s;
		int n = sqrt(s.size());
		vector<vector<char>> a(n, vector<char>(n));
		for (int i = 0, cnt = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				a[i][j] = s[cnt++];
		for (int i = n - 1; i >= 0; --i)
			for (int j = 0; j < n; ++j)
				cout << a[j][i];
		cout << '\n';
	}

	return 0;
}