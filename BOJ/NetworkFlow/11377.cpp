//11377

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
#define MAX 2020
#define PENALTY 2018
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

int ret;
int cap[MAX][MAX], flo[MAX][MAX], from[MAX];
vi node[MAX];

void networkFlow(int start, int end) {
	while (1) {
		fill(from, from + MAX, -1);
		queue<int> q;
		q.push(start);
		while (!q.empty()) {
			int cur = q.front();
			q.pop();
			for (auto& next : node[cur]) {
				if (cap[cur][next] - flo[cur][next] > 0 && from[next] == -1) {
					from[next] = cur;
					q.push(next);
					if (next == end) break;
				}
			}
		}

		if (from[end] == -1) break;

		int flow = INF;
		for (int i = end; i != start; i = from[i]) {
			flow = min(flow, cap[from[i]][i] - flo[from[i]][i]);
		}


		for (int i = end; i != start; i = from[i]) {
			flo[from[i]][i] += flow;
			flo[i][from[i]] -= flow;
		}

		ret += flow;
	}
}

bool cmp(int a, int b) {
	return node[a].size() > node[b].size();
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	//input
	int n, m, k; cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) {
		int t; cin >> t;
		for (int j = 0; j < t; j++) {
			int next; cin >> next;
			node[i].push_back(n + next);
			node[n + next].push_back(i);
			cap[i][n + next] = 1;
		}
	}

	//start to person
	for (int i = 1; i <= n; i++) {
		node[0].push_back(i);
		node[i].push_back(0);
		cap[0][i] = 1;
	}

	//task to end
	for (int i = n + 1; i <= n + m; i++) {
		node[i].push_back(MAX - 1);
		node[MAX - 1].push_back(i);
		cap[i][MAX - 1] = 1;
	}

	networkFlow(0, MAX - 1);

	//use penalty
	node[0].push_back(PENALTY);
	node[PENALTY].push_back(0);
	cap[0][PENALTY] = k;
	for (int i = 1; i <= n; i++) {
		node[PENALTY].push_back(i);
		node[i].push_back(PENALTY);
		cap[PENALTY][i] = 1;
	}

	networkFlow(0, MAX - 1);

	cout << ret;

	return 0;
}