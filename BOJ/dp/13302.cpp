//13302
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

int cache[105][45];
int n, m;
bool ban[101];

int f(int day, int coupon) {
	if (day > n) return 0;
	int& ret = cache[day][coupon];
	if (ret != -1) return ret;
	ret = INF;
	if (ban[day]) ret = min(ret, f(day + 1, coupon));
	else {
		ret = min(ret, f(day + 1, coupon) + 10000);
		ret = min(ret, f(day + 3, coupon + 1) + 25000);
		ret = min(ret, f(day + 5, coupon + 2) + 37000);
		if(coupon >= 3) ret = min(ret, f(day + 1, coupon - 3));
	}
	return ret;
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	memset(cache, -1, sizeof(cache));
	cin >> n >> m;
	while (m--) {
		int a; cin >> a;
		ban[a] = true;
	}
	cout << f(1, 0);

	return 0;
}