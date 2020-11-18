//13700
#include <bits/stdc++.h>
using namespace std;
#define INF 1000000000
#define MAX 10001
#define MOD 10007
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

struct P {
	int x, cnt;
};

int N, S, H, F, B, K;
bool police[100001];
bool chk[100001];

int BFS() {
	queue<P> q;
	chk[S] = true;
	q.push({ S, 0 });
	while (!q.empty()) {
		int x = q.front().x, cnt = q.front().cnt; q.pop();
		if (x == H) return cnt;
		for (int nx : {x + F, x - B}) {
			if (x<1 || x>N) continue;
			if (police[nx]) continue;
			if (chk[nx]) continue;
			chk[nx] = true;
			q.push({ nx, cnt + 1 });
		}
	}
	return -1;
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> N >> S >> H >> F >> B >> K;
	for (int i = 0; i < K; ++i) {
		int x; cin >> x;
		police[x] = true;
	}

	int ret = BFS();
	if (ret == -1) cout << "BUG FOUND";
	else cout << ret;

	return 0;
}