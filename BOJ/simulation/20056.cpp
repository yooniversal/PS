//20056
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
const int MAX = 100005, INF = 1000000001, MOD = 9901;

struct P {
	int r, c, m, s, d;
};

struct V {
	int m, s, d;
};

int dx[] = { -1,-1,0,1,1,1,0,-1 }, dy[] = { 0,1,1,1,0,-1,-1,-1 };
int N, M, K;
queue<P> q;
vector<V> a[51][51];

void solve() {
	while (!q.empty()) {
		int r = q.front().r, c = q.front().c, m = q.front().m;
		int s = q.front().s, d = q.front().d; q.pop();
		int ns = s % N;
		int nx = r + dx[d]*ns, ny = c + dy[d]*ns;
		if (nx >= N) nx -= N;
		if (ny >= N) ny -= N;
		if (nx < 0) nx += N;
		if (ny < 0) ny += N;

		a[nx][ny].push_back({ m,s,d });
	}
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> N >> M >> K;
	while (M--) {
		int r, c, m, s, d; cin >> r >> c >> m >> s >> d;
		q.push({ --r,--c,m,s,d });
	}

	int cnt = 0;
	while (K--) {
		// 이동
		solve();

		// 같은 칸에 있는 경우 처리
		for (int i = 0; i < N; ++i) for (int j = 0; j < N; ++j) {
			if (a[i][j].size() == 0) continue;
			if (a[i][j].size() == 1) {
				q.push({ i, j, a[i][j][0].m, a[i][j][0].s, a[i][j][0].d });
				continue;
			}
			int d = a[i][j][0].d % 2;
			for (auto& C : a[i][j]) {
				if (d % 2 == C.d % 2) continue;
				d = -1;
				break;
			}

			int sum_m = 0, sum_s = 0;
			for (auto& C : a[i][j]) sum_m += C.m, sum_s += C.s;
			sum_m /= 5, sum_s /= a[i][j].size();
			if (sum_m == 0) continue;
			if (d == -1) {
				for (int nd : {1, 3, 5, 7}) {
					q.push({ i, j, sum_m, sum_s, nd });
				}
			}
			else {
				for (int nd : {0, 2, 4, 6}) {
					q.push({ i, j, sum_m, sum_s, nd });
				}
			}
		}

		for (int i = 0; i < N; ++i) for (int j = 0; j < N; ++j) a[i][j].clear();
	}

	int ret = 0;
	while (!q.empty()) {
		ret += q.front().m; q.pop();
	}
	cout << ret << '\n';

	return 0;
}