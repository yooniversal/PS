//2605
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
const int MAX = 100005, INF = 1000000001, MOD = 1234567;

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n; cin >> n;
	list<int> a;
	for (int i = 1; i <= n; ++i) {
		int x; cin >> x;
		auto it = a.begin();
		for (int i = 0; i < x; ++i)
			++it;
		a.insert(it, i);
	}

	for (auto it = a.rbegin(); it != a.rend(); ++it)
		cout << *it << ' ';

	return 0;
}