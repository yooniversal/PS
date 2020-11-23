//10573
#include <bits/stdc++.h>
using namespace std;
#define INF 1000000000
#define MAX 10001
#define MOD 1000000007
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

string s;
ll cache[81][10][2];

ll f(int cur, int prev, int same) {
	//printf("cur:%d prev:%d same:%d\n", cur, prev, same);
	if (cur == s.size() - 1) {
		if (same) return 0;
		return 1;
	}
	ll& ret = cache[cur][prev][same];
	if (ret != -1) return ret;
	ret = 0;
	for (int i = 0; i <= 9; ++i) {
		if (prev > i) continue;
		if (same) {
			if (s[cur + 1]-'0' == i) ret += f(cur + 1, i, 1);
			else if (s[cur + 1]-'0' > i) ret += f(cur + 1, i, 0);
		}
		else {
			ret += f(cur + 1, i, 0);
		}
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
		cin >> s;

		bool pass = false;
		for(int i=1; i<s.size(); ++i)
			if (s[i - 1] > s[i]) {
				cout << -1 << '\n';
				pass = true;
				break;
			}
		if (pass) continue;

		ll ret = 0;
		for (int i = 0; i < s[0]-'0'; ++i) {
			ret += f(0, i, 0);
		}
		ret += f(0, s[0]-'0', 1);
		cout << ret << '\n';
	}

	return 0;
}