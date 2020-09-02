//17412

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
#define MAX 401
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

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	//input
	int n, p; cin >> n >> p;
	for (int i = 0; i < p; i++) {
		int a, b; cin >> a >> b;
		node[a].push_back(b);
		node[b].push_back(a);
		cap[a][b] = 1;
	}

	networkFlow(1, 2);

	cout << ret;

	return 0;
}