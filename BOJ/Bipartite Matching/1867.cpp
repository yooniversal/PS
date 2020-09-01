//1867

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
#define INF 987654321
#define MAX 501
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

vi stone[MAX];
bool chk[MAX];
int from[MAX];

bool dfs(int cur) {
	for (auto& next : stone[cur]) {
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

	//input
	int n, k; cin >> n >> k;
	vi row;
	for (int i = 0; i < k; i++) {
		int y, x; cin >> y >> x;
		stone[y].push_back(x);
		row.push_back(y);
	}
	sort(row.begin(), row.end());
	row.erase(unique(row.begin(), row.end()), row.end());

	int cnt = 0;
	for (int i = 0; i < row.size(); i++) {
		fill(chk, chk + MAX, false);
		if (dfs(row[i])) cnt++;
	}

	cout << cnt;

	return 0;
}