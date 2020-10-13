//14505
//non-complete
#include <bits/stdc++.h>
using namespace std;
#define INF 1000000007
#define MAX 50001
#define MOD 1000000000
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

int cache[31][31];
string s;

int g(int a, int b) {
	if (a > b) return 0;
	if (a == b) return 1;
	if (a + 1 == b) {
		if (s[a] == s[b]) return 3;
		return 2;
	}
	int& ret = cache[a][b];
	if (ret != -1) return ret;
	ret = g(a, b - 1) + g(a + 1, b);
	int add = s[a] == s[b] ? 1 : -g(a + 1, b - 1);
	ret += add;
	return ret;
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	memset(cache, -1, sizeof(cache));
	cin >> s;
	cout << g(0, s.size() - 1);

	return 0;
}