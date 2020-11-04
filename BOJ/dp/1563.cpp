//1563
#include <bits/stdc++.h>
using namespace std;
#define INF 1000000001
#define MAX 1001
#define MOD 1000000
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

int cache[MAX][3][4];
int n;

int f(int day, int late, int absent) {
	if (late >= 2 || absent >= 3) return 0;
	if (day == n) {
		if (late >= 2 || absent >= 3) return 0;
		return 1;
	}
	int& ret = cache[day][late][absent];
	if (ret != -1) return ret;
	ret = 0;
	ret += f(day + 1, late, 0) % MOD;
	ret += f(day + 1, late + 1, 0) % MOD;
	ret += f(day + 1, late, absent+1) % MOD;
	ret %= MOD;
	return ret;
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	memset(cache, -1, sizeof(cache));
	cin >> n;
	cout << f(0, 0, 0);

	return 0;
}