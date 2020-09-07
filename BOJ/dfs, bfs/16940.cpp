//16940

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
#define MAX 100001
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

vi e[MAX];
bool chk[MAX];
vi order;

bool cmp(int a, int b) {
	return order[a] < order[b];
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n; cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int a, b; cin >> a >> b;
		e[a].push_back(b);
		e[b].push_back(a);
	}

	vi ans(n + 1, 0); order.resize(n + 1, 0);
	for (int i = 1; i <= n; i++) {
		cin >> ans[i];
		order[ans[i]] = i;
	}
	for (int i = 1; i <= n; i++)
		sort(e[i].begin(), e[i].end(), cmp);

	vi ret; ret.push_back(0);
	queue<int> q;
	q.push(1);
	chk[1] = true;
	while (!q.empty()) {
		int cur = q.front(); q.pop();
		ret.push_back(cur);
		for (auto& next : e[cur]) {
			if (chk[next]) continue;
			chk[next] = true;
			q.push(next);
		}
	}
	
	if (ans == ret) cout << 1;
	else cout << 0;

	return 0;
}