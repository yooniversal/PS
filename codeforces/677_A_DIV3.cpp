#include <bits/stdc++.h>
using namespace std;
#define INF 1000000001
#define MAX 100005
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int t; cin >> t;
	while (t--) {
		string s; cin >> s;
		int len = s.size();
		int ret = (s[0] - '0' - 1) * 10;
		for (int i = 1; i <= len; ++i)
			ret += i;
		cout << ret << '\n';
	}

	return 0;
}