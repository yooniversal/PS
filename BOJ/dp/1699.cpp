//1699
#include <bits/stdc++.h>
using namespace std;
#define INF 1000000001
#define MAX 100001
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

int cache[MAX];

int f(int n) {
	if (n <= 0) return 0;
	
	int& ret = cache[n];
	if (ret != -1) return ret;

	ret = INF;

	int sn = sqrt(n);
	for (int i = sn; i >= 1; --i)
		ret = min(ret, f(n - i * i) + 1);
	return ret;
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	memset(cache, -1, sizeof(cache));

	int n; cin >> n;
	cout << f(n);

	return 0;
}