//2579

#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <cmath>
#include <algorithm>
#include <map>
using namespace std;
#define INF 1000000001
#define MAX 301
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

int n;
int a[MAX];
int cache[MAX][MAX];

int f(int cur, int con) {
	if (cur < 0 || con < 0) return 0;
	int& ret = cache[cur][con];
	if (ret != -1) return ret;
	if (con == 1) ret = max(f(cur - 2, 1), f(cur - 2, 2)) + a[cur];
	else ret = f(cur - 1, 1) + a[cur];
	return ret;
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	memset(cache, -1, sizeof(cache));

	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];

	cout << max(f(n - 1, 1), f(n-1, 2));

	return 0;
}