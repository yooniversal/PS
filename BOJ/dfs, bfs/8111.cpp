//8111
#include <bits/stdc++.h>
using namespace std;
#define INF 1000000007
#define MAX 4000005
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

int from[20001];
int chk[20001];

void bfs(int n) {
	memset(from, -1, sizeof(from));
	memset(chk, -1, sizeof(chk));
	chk[1 % n] = 0;
	queue<int> q;
	q.push(1%n);
	while (!q.empty()) {
		int cur = q.front(); q.pop();
		if (cur == 0) {
			string ret;
			for (int i = 0; from[i] != -1; i = chk[i])
				ret += from[i]+'0';
			reverse(ret.begin(), ret.end());
			cout << "1"+ret << '\n';
			return;
		}
		for (int i = 0; i <= 1; ++i) {
			int next = (cur * 10 + i) % n;
			if (chk[next] != -1) continue;
			from[next] = i;
			chk[next] = cur;
			q.push(next);
		}
	}
	cout << "BRAK" << '\n';
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		bfs(n);
	}

	return 0;
}