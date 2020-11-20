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
		int x, y, ret = 0; cin >> x >> y;
		ret += (max(x, y) - 1) * 2;
		if (x == y) ret += 2;
		else ret += 1;
		cout << ret << '\n';
	}

	return 0;
}