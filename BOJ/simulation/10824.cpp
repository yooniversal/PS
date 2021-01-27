//10824
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
const int MAX = 1000001, INF = 1000000001, MOD = 1234567;

ll f(string s) {
	ll ret = 0;
	for (int i = 0; i < s.size(); ++i)
		ret = ret * 10 + s[i] - '0';
	return ret;
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	string s1, s2, s3, s4; cin >> s1 >> s2 >> s3 >> s4;
	s1 += s2; s3 += s4;
	cout << f(s1) + f(s3) << '\n';

	return 0;
}