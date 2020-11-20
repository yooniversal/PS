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
		int n, c0, c1, h; cin >> n >> c0 >> c1 >> h;
		int ret = 0;
		string s; cin >> s;
		for (int i = 0; i < n; ++i) {
			if (s[i] == '0') {
				if (c0 <= c1 + h) ret += c0;
				else ret += c1 + h;
			}
			else {
				if (c1 <= c0 + h) ret += c1;
				else ret += c0 + h;
			}
		}
		cout << ret << '\n';
	}

	return 0;
}