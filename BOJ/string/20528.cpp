//20528
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
const int MAX = 500001, INF = 1000000001, MOD = 1234567;

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n; cin >> n;
	char first = '-';
	for (int i = 0; i < n; ++i) {
		string s; cin >> s;
		if (first == '-') first = s.front();
		else {
			if (first != s.front()) {
				cout << 0 << '\n';
				return 0;
			}
		}
	}
	
	cout << 1 << '\n';

	return 0;
}