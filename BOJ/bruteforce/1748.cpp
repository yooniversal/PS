//1748
#include <bits/stdc++.h>
using namespace std;
#define INF 1000000001
#define MAX 101
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

ll pow(int a, int n) {
	if (n == 0) return 1;
	ll ret = 1;
	for (int i = 1; i <= n; ++i)
		ret *= a;
	return ret;
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n; cin >> n;
	ll ret = 0;
	string ns = to_string(n);
	for (int i = 1; i < ns.size(); ++i) {
		if (i == 1) ret += 9;
		else {
			ret += pow(10, i - 1) * i * 9;
		}
	}
	ret += (n - pow(10, ns.size() - 1) + 1) * ns.size();

	cout << ret;

	return 0;
}