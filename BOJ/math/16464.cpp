//16464
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

bool solve(int n) {
	while (n) {
		n /= 2;
		if (n % 2 && n > 1) return false;
	}
	return true;
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		if (n % 2) cout << "Gazua\n";
		else {
			if (!solve(n)) cout << "Gazua\n";
			else cout << "GoHanGang\n";
		}
	}

	return 0;
}