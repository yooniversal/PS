//1509
#include <bits/stdc++.h>
using namespace std;
#define INF 1000000007
#define MAX 4000005
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

int cache[2501][2501];
int cache2[2501];
string s;

int f(int a, int b) {
	if (a >= b) return 1;
	int& ret = cache[a][b];
	if (ret != -1) return ret;
	ret = 0;
	if (s[a] == s[b])
		if (f(a + 1, b - 1)) 
			ret = 1;
	return ret;
}

int g(int cur) {
	if (cur >= s.size()) return 0;
	int& ret = cache2[cur];
	if (ret != -1) return ret;
	ret = INF;
	for (int i = cur; i < s.size(); ++i)
		if (f(cur, i))
			ret = min(ret, g(i+1)+1);
	return ret;
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	memset(cache, -1, sizeof(cache));
	memset(cache2, -1, sizeof(cache2));
	cin >> s;
	cout << g(0);

	return 0;
}