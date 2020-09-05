//10971

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
#define INF 1000000000
#define MAX 20005
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

int r[11][11];
bool visited[11];
int start, n, cnt, ret, ans=INF;

void dfs(int cur) {
	if (cnt == n) {
		if (!r[cur][start]) return;
		ret += r[cur][start];
		ans = min(ans, ret);
		ret -= r[cur][start];
		return;
	}
	for (int i = 0; i < n; i++) {
		if (visited[i]) continue;
		if (!r[cur][i]) continue;
		visited[i] = true;
		cnt++;
		ret += r[cur][i];
		dfs(i);
		ret -= r[cur][i];
		cnt--;
		visited[i] = false;
	}
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> r[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		visited[i] = true;
		start = i;
		cnt = 1;
		ret = 0;
		dfs(i);
		visited[i] = false;
	}

	cout << ans;

	return 0;
}