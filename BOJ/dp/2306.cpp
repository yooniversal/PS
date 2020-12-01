//2306
#include <bits/stdc++.h>
using namespace std;
#define INF 1000000001
#define MAX 2501
#define MOD 1000000007
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

string s;
int cache[501][501];

int f(int l, int r) {
	if (l >= r) return 0;
	int& ret = cache[l][r];
	if (ret != -1) return ret;
	ret = 0;
	if ((s[l] == 'a' && s[r] == 't') || (s[l] == 'g' && s[r] == 'c')) ret = max(ret, f(l + 1, r - 1) + 2);
	for (int m = l; m < r; ++m) {
		ret = max(ret, f(l, m) + f(m + 1, r));
	}
	return ret;
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	memset(cache, -1, sizeof(cache));
	cin >> s;
	cout << f(0, s.size() - 1);

	return 0;
}