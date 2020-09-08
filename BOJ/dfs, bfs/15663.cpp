//15663

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

bool chk[9];
int n, m;
vi tmp, ret;

void dfs(int cnt) {
	if (cnt == m) {
		for (int i = 0; i < m; i++)
			cout << ret[i] << " ";
		cout << '\n';
		return;
	}

	int prev = 0;
	for (int i = 0; i < n; i++) {
		if (chk[i] || prev == tmp[i]) continue;
		prev = tmp[i];
		chk[i] = true;
		ret.push_back(tmp[i]);
		dfs(cnt+1);
		ret.pop_back();
		chk[i] = false;
	}
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n >> m;
	tmp.resize(n);
	for (int i = 0; i < n; i++) cin >> tmp[i];
	sort(tmp.begin(), tmp.end());

	dfs(0);

	return 0;
}