//19236
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
const int MAX = 100005, INF = 1000000001, MOD = 9901;

struct P {
	int n, d;
};

struct F {
	int x, y, n;
	bool operator<(const F& f) {
		return n < f.n;
	}
};

int dx[] = { -1,-1,0,1,1,1,0,-1 }, dy[] = { 0,-1,-1,-1,0,1,1,1 };
int fnum[16], ret;

bool OOB(int x, int y) { return x < 0 || x >= 4 || y < 0 || y >= 4; }

// 맵, 상어의 위치, 점수
void solve(vector<vector<P>> a, int x, int y, int cnt) {
	ret = max(ret, cnt);
	a[x][y].n = 0;
	
	// 물고기 이동
	vector<F> fishes;
	for (int i = 0; i < 4; ++i) for (int j = 0; j < 4; ++j) {
		if (a[i][j].n == 0) continue; // 빈 칸 or 상어가 있는 칸
		fishes.push_back({ i,j,a[i][j].n });
	}
	sort(fishes.begin(), fishes.end());
	for (int i = 0; i < fishes.size(); ++i) {
		fnum[fishes[i].n] = i;
	}

	for (auto& fish : fishes) {
		// 현재 방향으로 갈 수 있는지
		int nx = fish.x + dx[a[fish.x][fish.y].d], ny = fish.y + dy[a[fish.x][fish.y].d];
		int od = a[fish.x][fish.y].d; // original direction

		// 45도 방향으로 조사
		nx = fish.x + dx[a[fish.x][fish.y].d], ny = fish.y + dy[a[fish.x][fish.y].d];
		while (OOB(nx, ny) || (nx == x && ny == y)) {
			++a[fish.x][fish.y].d;
			a[fish.x][fish.y].d %= 8;
			nx = fish.x + dx[a[fish.x][fish.y].d], ny = fish.y + dy[a[fish.x][fish.y].d];
		}

		auto tmp = a[fish.x][fish.y];
		a[fish.x][fish.y] = a[nx][ny];
		a[nx][ny] = tmp;

		auto ftmp = fishes[fnum[a[fish.x][fish.y].n]];
		fishes[fnum[a[fish.x][fish.y].n]].x = fishes[fnum[a[nx][ny].n]].x;
		fishes[fnum[a[fish.x][fish.y].n]].y = fishes[fnum[a[nx][ny].n]].y;
		fishes[fnum[a[nx][ny].n]].x = ftmp.x;
		fishes[fnum[a[nx][ny].n]].y = ftmp.y;
	}

	// 상어 이동
	int nx = x + dx[a[x][y].d], ny = y + dy[a[x][y].d];
	while (!OOB(nx, ny)) {
		if(a[nx][ny].n != 0) solve(a, nx, ny, cnt + a[nx][ny].n);
		nx += dx[a[x][y].d], ny += dy[a[x][y].d];
	}
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	vector<vector<P>> a(4, vector<P>(4));
	for (int i = 0; i < 4; ++i) for (int j = 0; j < 4; ++j) {
		cin >> a[i][j].n >> a[i][j].d;
		--a[i][j].d;
	}

	solve(a, 0, 0, a[0][0].n);
	cout << ret << '\n';

	return 0;
}