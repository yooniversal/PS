//9742
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

	string s; int n;
	while (cin >> s >> n) {
		string tmp = s;
		int cnt = 0;
		bool flag = true;
		do {
			if (++cnt == n) {
				flag = false;
				cout << s << ' ' << n << " = " << tmp << '\n';
			}
		} while(next_permutation(tmp.begin(), tmp.end()));
		if (flag) {
			cout << s << ' ' << n << " = No permutation\n";
		}
	}

	return 0;
}