//16947
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
const int MAX = 500001, INF = 1000000001, MOD = 1234567;

int n, ret[3001];
vi adj[3001];
bool chk[3001], isCycle[3001], foundCycle;

void DFS(int st, int cur, int prev) {
	//printf("st:%d cur:%d\n", st, cur);
	if (st == cur) {
		foundCycle = true;
		isCycle[cur] = true;
		return;
	}

	for (int& next : adj[cur]) {
		//printf("cur:%d next:%d chk[next]:%d\n", cur,next,chk[next]);
		if (chk[next] || next == prev) continue;
		//cout << "**\n";
		chk[next] = true;
		DFS(st, next, cur);
		chk[next] = false;
		if (foundCycle) {
			isCycle[cur] = true;
			return;
		}
	}

	
}

void BFS(int cur) {
	memset(chk, 0, size(chk));
	queue<ii> q;
	chk[cur] = true;
	q.push({ cur,0 });
	while (!q.empty()) {
		int x = q.front().first, cnt = q.front().second; q.pop();
		//printf("x:%d cnt:%d\n", x, cnt);
		if (isCycle[x]) {
			ret[cur] = cnt;
			break;
		}
		for (int& next : adj[x]) {
			if (chk[next]) continue;
			chk[next] = true;
			q.push({ next, cnt + 1 });
		}
	}
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n;
	for (int i = 0; i < n; ++i) {
		int a, b; cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	for (int i = 1; i <= n; ++i) {
		for (int& next : adj[i]) {
			chk[next] = true;
			DFS(i, next, i);
			chk[next] = false;

			if (foundCycle) {
				i = n + 1;
				break;
			}
		}
	}

	for (int i = 1; i <= n; ++i) 
		if(!isCycle[i]) BFS(i);
	for (int i = 1; i <= n; ++i) cout << ret[i] << ' ';
	cout << '\n';

	return 0;
}