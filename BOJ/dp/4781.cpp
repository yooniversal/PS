//4781
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

int cache[10001];
int n, m;
vii a;

int f(int money) {
	if (money == 0) return 0;
	int& ret = cache[money];
	if (ret != -1) return ret;
	ret = 0;
	for(int i=0; i<n; ++i)
		if(money-a[i].second>=0)
			ret = max(ret, f(money-a[i].second) + a[i].first);
	return ret;
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	while (1) {
		memset(cache, -1, sizeof(cache));
		int m1, m2;
		scanf("%d %d.%d", &n, &m1, &m2);
		if (n == 0) break;
		m = m1 * 100 + m2;
		a.resize(n);
		for (int i = 0; i < n; ++i) {
			int price, m1, m2;
			scanf("%d %d.%d", &price, &m1, &m2);
			a[i].first = price;
			a[i].second = m1*100 + m2;
		}
		cout << f(m) << '\n';
	}

	return 0;
}