//12919
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
const int MAX = 100005, INF = 1000000001, MOD = 9901;

string a, b;

bool solve(string s) {
	if (s.size() == a.size()) {
		if (s == a) return true;
		return false;
	}

	bool ret = false;
	if(s.back() == 'A') ret |= solve(s.substr(0, s.size()-1));
	if (s[0] == 'B') {
		string tmp = s.substr(1);
		reverse(tmp.begin(), tmp.end());
		ret |= solve(tmp);
	}

	return ret;
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> a >> b;
	cout << solve(b) << '\n';

	return 0;
}