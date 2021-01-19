//10799
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
const int MAX = 100001, INF = 1000000001, MOD = 1234567;

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	string s; cin >> s;
	int tmp = 0, ret = 0;
	for (int i = 0; i < s.size(); ++i) {
		if (s[i] == '(') ++tmp;
		else {
			--tmp;
			if (s[i - 1] != '(') {
				++ret;
				continue;
			}
			ret += tmp;
		}
	}
	cout << ret << '\n';

	return 0;
}