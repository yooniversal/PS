//2666
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

int n, k;
vi arr;
int cache[21][21][21];

int f(int cur, int a, int b) {
	if (cur == k) return 0;
	int& ret = cache[cur][a][b];
	if (ret != -1) return ret;
	ret = INF;
	ret = min(ret, f(cur + 1, arr[cur], b) + abs(arr[cur] - a));
	ret = min(ret, f(cur + 1, a, arr[cur]) + abs(arr[cur] - b));
	return ret;
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	memset(cache, -1, sizeof(cache));
	cin >> n;
	int a, b; cin >> a >> b;
	cin >> k;
	arr.resize(k);
	for (int i = 0; i < k; ++i) cin >> arr[i];
	cout << f(0, a, b);

	return 0;
}