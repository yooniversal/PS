//9658
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

int cache[1001][2];

int f(int cur, int who) {
	if (cur <= 1) return !who;
	if (cur == 2) return who;
	if (cur == 3) return !who;
	if (cur == 4) return who;
	int& ret = cache[cur][who];
	if (ret != -1) return ret;
	if (f(cur - 1, !who) == who || f(cur - 3, !who) == who || f(cur - 4, !who) == who) ret = who;
	else ret = !who;
	return ret;
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	memset(cache, -1, sizeof(cache));
	int n; cin >> n;
	if (f(n, 1)) cout << "SK";
	else cout << "CY";

	return 0;
}