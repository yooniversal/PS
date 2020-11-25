//2591
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
int cache[41];

int f(int cur) {
	if (cur > s.size()) return 0;
	if (cur == s.size()) return 1;
	int& ret = cache[cur];
	if (ret != -1) return ret;
	ret = 0;
	if (s[cur] == '0') return 0;
	ret += f(cur + 1);
	if (cur < s.size() - 1)
		if((s[cur] == '3' && s[cur+1] <= '4') || (s[cur] > '0' && s[cur] <= '2')) ret += f(cur + 2);
	return ret;
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	memset(cache, -1, sizeof(cache));
	cin >> s;
	cout << f(0) << '\n';

	return 0;
}