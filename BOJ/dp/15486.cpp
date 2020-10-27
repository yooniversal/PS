//15486
#include <bits/stdc++.h>
using namespace std;
#define INF 1000000001
#define MAX 100005
#define MOD 1000000000
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

struct P {
	int day, price;
	P() : day(-1), price(-1) {}
};

int n;
int cache[1500001];
P a[1500001];

int f(int cur) {
	if (cur >= n) return 0;
	int& ret = cache[cur];
	if (ret != -1) return ret;
	ret = 0;
	if(cur+a[cur].day<=n) ret = max(ret, f(cur + a[cur].day) + a[cur].price);
	ret = max(ret, f(cur + 1));
	return ret;
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	memset(cache, -1, sizeof(cache));
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i].day >> a[i].price;
	}
	cout << f(0);

	return 0;
}