//2188

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
#define MAX 201
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

int from[MAX];
bool chk[MAX];
vi cow[MAX];

bool dfs(int cur) {
	for (auto& next : cow[cur]) {
		if (chk[next]) continue;
		chk[next] = true;

		if (from[next] == 0 || dfs(from[next])) {
			from[next] = cur;
			return true;
		}
	}
	return false;
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m; cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		int s; cin >> s;
		for (int j = 0; j < s; j++) {
			int place; cin >> place;
			cow[i].push_back(place);
		}
	}

	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		fill(chk, chk + MAX, false);
		if (dfs(i)) cnt++;
	}
	
	cout << cnt << '\n';

	return 0;
}