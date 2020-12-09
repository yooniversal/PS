//1251
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

	string s; cin >> s;

	vector<string> ret;
	int len = s.size();
	for (int i = 0; i < len - 2; ++i) {
		for (int j = i + 1; j < len - 1; ++j) {
			string s1 = s.substr(0, i+1);
			reverse(s1.begin(), s1.end());
			string s2 = s.substr(i+1, j-i);
			reverse(s2.begin(), s2.end());
			string s3 = s.substr(j+1);
			reverse(s3.begin(), s3.end());
			ret.push_back(s1 + s2 + s3);
		}
	}
	sort(ret.begin(), ret.end());
	cout << ret[0] << '\n';

	return 0;
}