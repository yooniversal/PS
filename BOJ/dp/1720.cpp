//1720
#include <bits/stdc++.h>
using namespace std;
#define INF 1000000001
#define MAX 4005
#define MOD 1000000000
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

int cache[31];
int n;

int f(int cur) {
	if (cur < 0) return 0;
	if (cur == 0) return 1;
	int& ret = cache[cur];
	if (ret != -1) return ret;
	ret = 0;
	ret += f(cur - 1) + 2 * f(cur - 2);
	return ret;
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	memset(cache, -1, sizeof(cache));
	cin >> n;
	if (n % 2) {
		cout << (f(n) + f((n - 1) / 2)) / 2;
	}
	else {
		cout << (f(n) + f(n / 2) + f((n - 2) / 2) * 2) / 2;
	}

	return 0;
}