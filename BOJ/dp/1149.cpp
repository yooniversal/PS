//1149

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
#define MAX 1001
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

int a[MAX][MAX];
int cache[MAX][MAX];
int n;

int f(int r, int c) {
	if (r < 0) return 0;
	int& ret = cache[r][c];
	if (ret != -1) return ret;
	
	ret = INF;
	for (int i = 0; i < 3; i++)
		if(i != c)
			ret = min(ret, f(r-1, i) + a[r][i]);
	return ret;
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	memset(cache, -1, sizeof(cache));

	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < 3; j++)
			cin >> a[i][j];
	
	int ret = INF;
	for (int i = 0; i < 3; i++) {
		ret = min(ret, f(n, i));
	}

	cout << ret;

	return 0;
}