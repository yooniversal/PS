//1075
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
const int MAX = 5005, INF = 1000000001, MOD = 1234567;

int f(int n, int t) {
	return (n / 100) * 100 + t;
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	//ios_base::sync_with_stdio(false);

	int n, m; scanf("%d %d", &n, &m);
	for(int i=0; i<=99; ++i)
		if (f(n, i) % m == 0) {
			printf("%02d\n", i);
			return 0;
		}

	return 0;
}