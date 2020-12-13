//11094
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

	string t = "Simon says";

	int n; cin >> n;
	cin.ignore();
	while (n--) {
		string s;
		getline(cin, s);
		bool flag = true;
		for (int i = 0; i < 10; ++i) {
			if (s[i] != t[i]) {
				flag = false;
				break;
			}
		}
		if (flag) {
			if (s.size() < 10) continue;
			for (int i = 10; i < s.size(); ++i) cout << s[i];
			cout << '\n';
		}
	}

	return 0;
}