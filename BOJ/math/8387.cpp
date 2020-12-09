//8387
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
const int MAX = 1001, INF = 1000000001, MOD = 1234567;

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n; cin >> n;
	string s1, s2; cin >> s1 >> s2;

	int ret = 0;
	for (int i = 0; i < n; ++i)
		if (s1[i] == s2[i]) ++ret;
	cout << ret << '\n';

	return 0;
}