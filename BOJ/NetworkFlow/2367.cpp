//2367
#include <bits/stdc++.h>
using namespace std;
#define INF 1000000001
#define MAX 1000001
#define MOD 1000000000
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

const int START = 300 + 1, END = 300 + 2;
int ret;
int cap[401][401], flo[401][401], from[401];
vi node[401];

void networkFlow() {
	while (1) {
		fill(from, from + 401, -1);
		queue<int> q;
		q.push(START);
		while (!q.empty()) {
			int cur = q.front();
			q.pop();
			for (auto& next : node[cur]) {
				if (cap[cur][next] - flo[cur][next] > 0 && from[next] == -1) {
					from[next] = cur;
					q.push(next);
					if (next == END) break;
				}
			}
		}

		if (from[END] == -1) break;

		int flow = INF;
		for (int i = END; i != START; i = from[i]) {
			flow = min(flow, cap[from[i]][i] - flo[from[i]][i]);
		}

		for (int i = END; i != START; i = from[i]) {
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

	int n, k, d; cin >> n >> k >> d;

	//start -> 사람
	for (int person = 1; person <= n; ++person) {
		node[START].push_back(person);
		node[person].push_back(START);
		cap[START][person] = k;
	}

	//음식 -> end
	for (int food = 200+1; food <= 200+d; ++food) {
		int cnt; cin >> cnt;
		node[food].push_back(END);
		node[END].push_back(food);
		cap[food][END] = cnt;
	}

	//사람 -> 음식
	for (int person = 1; person <= n; ++person) {
		int t; cin >> t;
		for (int i = 0; i < t; ++i) {
			int food; cin >> food;
			food += 200;
			node[person].push_back(food);
			node[food].push_back(person);
			cap[person][food] = 1;
		}
	}

	networkFlow();
	cout << ret;

	return 0;
}