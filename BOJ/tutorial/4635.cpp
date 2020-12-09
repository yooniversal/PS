//4635
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
		int prev = 0, ret = 0;
		for (int i = 0; i < n; ++i) {
			int speed, time; cin >> speed >> time;
			ret += speed * (time - prev);
			prev = time;
		}
		cout << ret << " miles\n";
	}

	return 0;
}