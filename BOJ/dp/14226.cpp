//9376
#include <bits/stdc++.h>
using namespace std;
#define INF 1000000000
#define MAX 4000005
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

int cache[3001][20001];
int n;

int f(int d, int p) {
	if (d == n) return 0;
	int& ret = cache[d][p];
	if (ret != -1) return ret;
	ret = INF;
	ret = min(ret, f(d, d) + 1);
	if (d + p <= 2*n) ret = min(ret, f(d + p, p) + 1);
	if (d - 1 >= 1) ret = min(ret, f(d - 1, p) + 1);
	return ret;
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	memset(cache, -1, sizeof(cache));
	cin >> n;
	cout << f(1, 0);

	return 0;
}