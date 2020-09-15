//Algospot
//TILING2

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
#define MAX 101
#define MOD 1000000007
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

int cache[MAX];
int n;

int f(int cur) {
	if (cur <= 0) return 0;
	int& ret = cache[cur];
	if (ret != -1) return ret % MOD;
	ret = (f(cur - 1) + f(cur - 2)) % MOD;
	return ret;
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int t; cin >> t;
	while (t--) {
		memset(cache, -1, sizeof(cache));
		cache[1] = 1; cache[2] = 2;
		cin >> n;
		cout << f(n) << '\n';
	}

	return 0;
}