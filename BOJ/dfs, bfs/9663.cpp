//9663

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
#define MAX 100001
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

int n, ret;
int chk[16][16];

void dfs(int y, int x) {
	if (y == n - 1) {
		ret++;
		return;
	}
	for (int i = 0; i < n; i++) {
		chk[i][x]++;
		if (y + i <= n - 1 && x + i <= n - 1)
			chk[y + i][x + i]++;
		if (y + i <= n - 1 && x - i >= 0)
			chk[y + i][x - i]++;
	}
	for (int i = 0; i < n; i++) {
		if (chk[y + 1][i]) continue;
		dfs(y + 1, i);
	}
	for (int i = 0; i < n; i++) {
		chk[i][x]--;
		if (y + i <= n - 1 && x + i <= n - 1)
			chk[y + i][x + i]--;
		if (y + i <= n - 1 && x - i >= 0)
			chk[y + i][x - i]--;
	}
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n;
	for (int i = 0; i < n; i++)
		dfs(0, i);
	cout << ret;

	return 0;
}