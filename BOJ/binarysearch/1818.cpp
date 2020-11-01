//1818
#include <bits/stdc++.h>
using namespace std;
#define INF 1000000001
#define MAX 1000001
#define MOD 1000000000
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	vi a, target;
	int n; cin >> n;
	a.resize(n);
	for (int i = 0; i < n; ++i) cin >> a[i];
	target.push_back(a[0]);
	for (int i = 1; i < n; ++i) {
		if (target.back() < a[i])
			target.push_back(a[i]);
		else {
			auto it = lower_bound(target.begin(), target.end(), a[i]);
			*it = a[i];
		}
	}
	cout << n-target.size();

	return 0;
}