//2698
#include <bits/stdc++.h>
using namespace std;
#define INF 1000000001
#define MAX 100005
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

int cache[101][101][2];
int n, k;

int f(int a, int b, int prev) {
	if (a == n) {
		if (b == k) return 1;
		return 0;
	}
	int& ret = cache[a][b][prev];
	if (ret != -1) return ret;
	ret = 0;
	if (!prev) {
		ret += f(a + 1, b, 1);
		ret += f(a + 1, b, 0);
	}
	else {
		ret += f(a + 1, b + 1, 1);
		ret += f(a + 1, b, 0);
	}
	return ret;
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int t; cin >> t;
	while (t--) {
		memset(cache, -1, sizeof(cache));
		cin >> n >> k;
		cout << f(0, 0, 0) << '\n';
	}

	return 0;
}