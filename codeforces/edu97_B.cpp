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
		int n; cin >> n;
		string s; cin >> s;
		int z = 0, o = 0;
		for (int i = 0; i < n-1; ++i) {
			if (s[i] == '0') {
				if (s[i] == s[i + 1])
					++z;
			}
			else {
				if (s[i] == s[i + 1])
					++o;
			}
		}
		cout << max(z, o) << '\n';
	}

	return 0;
}