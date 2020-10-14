//13398
#include <bits/stdc++.h>
using namespace std;
#define INF 1000000001
#define MAX 100005
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

int cache[MAX][4];
int arr[MAX];
int n;

int f(int a, int b) {
	if (a == n) {
		if (b == 0) return -INF;
		return 0;
	}
	int& ret = cache[a][b];
	if (ret != -1) return ret;
	ret = -INF;
	if (b == 0) {
		ret = max(ret, f(a + 1, 0));
		ret = max(ret, f(a + 1, 1) + arr[a + 1]);
	}
	else if (b == 1) {
		ret = max(ret, f(a + 1, 1) + arr[a + 1]);
		ret = max(ret, f(a + 1, 2));
		ret = max(ret, f(a + 1, 3));
	}
	else if (b == 2) {
		ret = max(ret, f(a + 1, 2) + arr[a + 1]);
		ret = max(ret, f(a + 1, 3));
	}
	else
		ret = max(ret, f(a + 1, 3));
	return ret;
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	memset(cache, -1, sizeof(cache));
	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> arr[i];
	cout << f(0, 0);

	return 0;
}