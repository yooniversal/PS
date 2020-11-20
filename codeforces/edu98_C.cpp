#include <bits/stdc++.h>
using namespace std;
#define INF 1000000001
#define MAX 300005
#define MOD 1000000007
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
		int o = 0, c = 0;
		int ret = 0;
		for (int i = 0; i < s.size(); ++i) {
			if (s[i] == '(') ++o;
			else if (s[i] == ')') {
				if (o <= 0) continue;
				--o; ++ret;
			}
			else if (s[i] == '[') ++c;
			else {
				if (c <= 0) continue;
				--c; ++ret;
			}
		}
		cout << ret << '\n';
	}

	return 0;
}