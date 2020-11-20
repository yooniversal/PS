//13235
#include <bits/stdc++.h>
using namespace std;
#define INF 1000000000
#define MAX 605
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

	string s; cin >> s;
	for (int l = 0, r = s.size() - 1; l < r; ++l, --r) {
		if (s[l] != s[r]) {
			cout << "false" << '\n';
			return 0;
		}
	}
	cout << "true" << '\n';

	return 0;
}