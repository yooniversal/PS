//16472
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

int a[27], n;
string s;

bool can() {
	for (int i = 0, cnt = 0; i < 27; ++i) {
		if (a[i]) if (++cnt > n) return false;
	}
	return true;
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n >> s;

	int ret = 0;
	if (s.size() == 1) { cout << 1 << '\n'; return 0; }
	++a[s[0] - 'a']; ++a[s[1] - 'a'];
	for (int l = 0, r = 1; r < s.size();) {
		if (can()) {
			ret = max(ret, r - l + 1);
			++r; ++a[s[r] - 'a'];
		}
		else {
			--a[s[l++] - 'a'];
		}
	}
	cout << ret;

	return 0;
}