//12085
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

	int t, cnt=1; cin >> t;
	while (t--) {
		int n; cin >> n;
		cin.ignore();
		vector<string> a;
		for (int i = 0; i < n; ++i) {
			string s;
			getline(cin, s);
			a.push_back(s);
		}

		int ret = 0;
		for (int i = 1; i < n; ++i) {
			if (a[i - 1] > a[i])
				swap(a[i-1], a[i]), ++ret;
		}
		cout << "Case #" << cnt++ << ": " << ret << '\n';
	}

	return 0;
}