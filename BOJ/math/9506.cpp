//9506
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

	while (1) {
		int n; cin >> n;
		if (n == -1) break;

		int ret = 0;
		vi tmp;
		for (int i = 1; i <= sqrt(n); ++i)
			if (n % i == 0) {
				ret += i;
				tmp.push_back(i);
				if (i != 1) ret += n / i, tmp.push_back(n / i);
			}
		if (ret == n) {
			sort(tmp.begin(), tmp.end());
			cout << n << " = ";
			for (int i = 0; i < tmp.size(); ++i)
				if (i != tmp.size() - 1)
					cout << tmp[i] << " + ";
				else
					cout << tmp[i] << '\n';
		}
		else
			cout << n << " is NOT perfect.\n";
	}

	return 0;
}