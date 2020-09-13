//13023

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
#define MAX 2001
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

vi node[MAX];
bool ret, chk[MAX];
int n, m;
int cnt;

void dfs(int cur) {
	if (cnt == 5) {
		ret = true;
		return;
	}

	for (auto& next : node[cur]) {
		if (chk[next]) continue;
		chk[next] = true;
		cnt++;
		dfs(next);
		cnt--;
		chk[next] = false;
	}
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	cin >> n >> m;
	while (m--) {
		int a, b; cin >> a >> b;
		node[a].push_back(b);
		node[b].push_back(a);
	}

	for (int i = 0; i < n; i++) {
		fill(chk, chk + n, false);
		cnt = 1;
		chk[i] = true;
		dfs(i);
		chk[i] = false;
		if (ret) break;
	}

	cout << ret ? 1 : 0;

	return 0;
}