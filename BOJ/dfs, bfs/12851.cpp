//12851
#include <bits/stdc++.h>
using namespace std;
#define INF 1000000000
#define MAX 4000005
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

int n, k;
int d[100005];

void bfs() {
	int cnt = 0;
	queue<int> q;
	q.push(n);
	while (!q.empty()) {
		int cur = q.front(); q.pop();
		if (cur == k) ++cnt;
		if (d[k] && d[cur] > d[k]) break;
		for (int nx : {cur - 1, cur + 1, cur * 2}) {
			if (nx < 0 || nx>100000) continue;
			if (d[nx] && d[nx] != d[cur] + 1) continue;
			q.push(nx);
			d[nx] = d[cur] + 1;
		}
	}
	cout << d[k] << '\n' << cnt;
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n >> k;
	if (n == k) {
		cout << 0 << '\n' << 1;
		return 0;
	}
	bfs();

	return 0;
}