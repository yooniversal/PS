//6086

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
#define MAX 701
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

int from[MAX];
int c[MAX][MAX], f[MAX][MAX];
int ret;
vi pipe[123];

void networkflow(int start, int end) {
	while (1) {
		fill(from, from + MAX, -1);
		queue<int> q;
		q.push(start);
		while (!q.empty()) {
			int cur = q.front(); q.pop();
			for (auto& next : pipe[cur]) {
				if (c[cur][next] - f[cur][next] > 0 && from[next] == -1) {
					from[next] = cur;
					q.push(next);
					if (next == end) break;
				}
			}
		}
		
		if (from[end] == -1) break;

		int flow = INF;
		for (int i = end; i != start; i = from[i]) {
			flow = min(flow, c[from[i]][i] - f[from[i]][i]);
		}

		for (int i = end; i != start; i = from[i]) {
			f[from[i]][i] += flow;
			f[i][from[i]] -= flow;
		}

		ret += flow;
	}
}

int idx(char a) {
	if ('A' <= a && a <= 'Z') return a - 'A';
	if ('a' <= a && a <= 'z') return a - 'a' + 26;
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		char a, b; cin >> a >> b;
		int capacity; cin >> capacity;
		pipe[idx(a)].push_back(idx(b));
		pipe[idx(b)].push_back(idx(a));
		c[idx(a)][idx(b)] += capacity;
		c[idx(b)][idx(a)] += capacity;
	}

	networkflow(0, 'Z'-'A');

	cout << ret;

	return 0;
}