//13163
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
	cin.ignore();
	while (n--) {
		string s;
		getline(cin, s);
		bool blank = false;
		cout << "god";
		for (int i = 0; i < s.size(); ++i) {
			if (s[i] == ' ') {
				blank = true;
				continue;
			}
			if (!blank) continue;
			cout << s[i];
		}
		cout << '\n';
	}

	return 0;
}