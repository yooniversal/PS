//15658

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
#define MAX 20001
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

int n;
int retMAX = -INF, retMIN = INF;
vi op, needOP;
vi num;
int a, b, c, d;

void dfs(int idx, int ret, int a, int b, int c, int d) {
	if (idx == n) {
		retMAX = max(retMAX, ret);
		retMIN = min(retMIN, ret);
		return;
	}
	if (a) dfs(idx + 1, ret + num[idx], a-1, b, c, d);
	if (b) dfs(idx + 1, ret - num[idx], a, b-1, c, d);
	if (c) dfs(idx + 1, ret * num[idx], a, b, c-1, d);
	if (d) dfs(idx + 1, ret / num[idx], a, b, c, d-1);
	
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n;
	num.resize(n);
	for (int i = 0; i < n; i++) cin >> num[i];
	cin >> a >> b >> c >> d;

	dfs(1, num[0], a, b, c, d);

	cout << retMAX << '\n' << retMIN;

	return 0;
}