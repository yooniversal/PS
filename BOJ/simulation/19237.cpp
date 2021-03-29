//19237
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
const int MAX = 100005, INF = 1000000001, MOD = 9901;

struct MAP {
	bool smell;
	int n, cnt;
	MAP() : smell(false), n(0), cnt(0) {}
};

struct P {
	int x, y, d;
	bool dead;
	P(int a, int b, int c, bool d) : x(a), y(b), d(c), dead(d) {}
	P() {
		P(-1, -1, -1, true);
	}
};

struct Q {
	int n, x, y, nx, ny;
};

MAP a[21][21];
int dx[] = { -1,1,0,0 }, dy[] = { 0,0,-1,1 };
int N, M, K, alive, ret;
int pd[401][4][4]; // 상어 번호, 현재 방향, 우선순위
P shark[401];

bool OOB(int x, int y) { return x < 0 || x >= N || y < 0 || y >= N; }

void solve() {
	queue<int> q;
	vector<Q> tmp; // 이동 정보
	for (int i = 1; i <= M; ++i) {
		q.push(i);
		int nx = -1, ny = -1;
		for (int j : pd[i][shark[i].d]) {
			nx = shark[i].x + dx[j], ny = shark[i].y + dy[j];
			if (OOB(nx, ny)) continue;
			shark[i].d = j;
			break;
		}
		tmp.push_back({ i, shark[i].x, shark[i].y, nx, ny });
	}
	while (!q.empty()) {
		int cur = q.front(); q.pop();
		if (shark[cur].dead) continue;
		// 모든 상어들의 움직임 및 냄새 처리
		if (cur == 1) {
			++ret;
			// 이동
			vi map_cnt[21][21];
			for (int i = 0; i < tmp.size(); ++i) {
				map_cnt[tmp[i].nx][tmp[i].ny].emplace_back(tmp[i].n);
				shark[tmp[i].n].x = tmp[i].nx;
				shark[tmp[i].n].y = tmp[i].ny;
			}
			// 겹치는 상어 처리
			for (int i = 0; i < N; ++i) for (int j = 0; j < N; ++j) {
				if (map_cnt[i][j].size() <= 1) continue;
				sort(map_cnt[i][j].begin(), map_cnt[i][j].end());
				for (int k = 1; k < map_cnt[i][j].size(); ++k) {
					shark[map_cnt[i][j][k]].dead = true;
					--alive;
				}
			}
			// 냄새 카운트
			for (int i = 0; i < N; ++i) for(int j=0; j<N; ++j) {
				if (!a[i][j].smell) continue;
				--a[i][j].cnt;
				if (a[i][j].cnt == 0) {
					a[i][j].smell = false;
					a[i][j].n = 0;
				}
			}
			// 냄새 뿌리기
			for (auto& s : tmp) {
				if (shark[s.n].dead) continue;
				a[s.nx][s.ny].smell = true;
				a[s.nx][s.ny].n = s.n;
				a[s.nx][s.ny].cnt = K;
			}
			tmp.clear();
		}
		if (alive == 1 || ret > 1000) break;

		// 상어 다음 방향 설정
		// 빈 칸 찾기 & 우선순위 고려
		bool flag = true;
		for (int i : pd[cur][shark[cur].d]) {
			int nx = shark[cur].x + dx[i], ny = shark[cur].y + dy[i];
			if (OOB(nx, ny) || a[nx][ny].smell) continue;
			flag = false;
			shark[cur].d = i;
			tmp.push_back({ cur, shark[cur].x, shark[cur].y, nx, ny });
			break;
		}

		if (flag) {
			// 본인 냄새 찾기 & 우선순위 고려
			for (int i : pd[cur][shark[cur].d]) {
				int nx = shark[cur].x + dx[i], ny = shark[cur].y + dy[i];
				if (OOB(nx, ny) || a[nx][ny].n != cur) continue;
				shark[cur].d = i;
				tmp.push_back({ cur, shark[cur].x, shark[cur].y, nx, ny });
				break;
			}
		}
		q.push(cur);
	}
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> N >> M >> K;
	alive = M;

	for (int i = 0; i < N; ++i) for (int j = 0; j < N; ++j) {
		int c; cin >> c;
		if (c) {
			shark[c] = P(i,j,-1,false);
			a[i][j].smell = true;
			a[i][j].n = c;
			a[i][j].cnt = K;
		}
	}
	for (int i = 1; i <= M; ++i) {
		cin >> shark[i].d;
		--shark[i].d;
	}
	for (int i = 1; i <= M; ++i) {
		for (int j = 0; j < 4; ++j) {
			for (int k = 0; k < 4; ++k) {
				cin >> pd[i][j][k];
				--pd[i][j][k];
			}
		}
	}

	solve();
	if (ret <= 1000) cout << ret << '\n';
	else cout << -1 << '\n';

	return 0;
}