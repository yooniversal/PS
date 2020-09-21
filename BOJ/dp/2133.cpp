//11403
#include <bits/stdc++.h>
using namespace std;
#define INF 1000000001
#define MAX 1001
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

int cache[31], cache2[31];

int g(int n);
int f(int n);

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	memset(cache, -1, sizeof(cache));
	memset(cache2, -1, sizeof(cache2));

	int n; cin >> n;
	cout << f(n);

	return 0;
}

int g(int n) {
	int& ret = cache2[n];
	if (ret != -1) return ret;
	ret = f(n - 1) + g(n - 2);
	return ret;
}

int f(int n) {
	if (n < 0) return 0;
	if (n == 0) return 1;
	int& ret = cache[n];
	if (ret != -1) return ret;
	ret = f(n - 2) + 2*g(n-1);
	return ret;
}