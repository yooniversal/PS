//23325
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
const int MAX = 100005, INF = 1000000001, MOD = 9901;

int cache[200005][2][2];
string s;

int f(int i, int m, int before) {
	if (i > s.size() - 1) {
		if (m == 0) return -INF;
		return 0;
	}

	int& ret = cache[i][m][before];
	if (ret != -1) return ret;
	ret = -INF;

	if (m == 0) {
		if (s[i] == '+') {
			if (i + 1 <= s.size() - 1 && s[i + 1] == '-') {
				if(before == 0) ret = max(ret, f(i + 2, 1, 0) + 11);
				else ret = max(ret, f(i + 2, 1, 0) - 11);
			}

			if (before == 0) ret = max(ret, f(i + 1, 1, 0) + 10);
			else ret = max(ret, f(i + 1, 1, 0) - 10);
		}
		else {
			if(before == 0) ret = max(ret, f(i + 1, 1, 0) + 1);
			else ret = max(ret, f(i + 1, 1, 0) - 1);
		}
	}
	else {
		if (s[i] == '+') ret = max(ret, f(i + 1, 0, 0));
		else ret = max(ret, f(i + 1, 0, 1));
	}

	return ret;
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> s;
	memset(cache, -1, sizeof(cache));

	cout << f(0, 0, 0) << '\n';

	return 0;
}