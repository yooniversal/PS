//17472
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
const int MAX = 100005, INF = 1000000001, MOD = 9901;

class triple {
public:
	int dist, s, e;
	triple(int dist, int s, int e) : dist(dist), s(s), e(e) {}

	bool operator <(triple& triple) {
		return this->dist < triple.dist;
	}
};


struct P {
	bool result;
	int island, cnt;
};

int dx[] = { -1,0,1,0 }, dy[] = { 0,1,0,-1 };
int n, m, a[11][11];
int island[11][11], uni[7], lu;
int d[7][7];
bool chk[11][11];

bool OOB(int x, int y) { return x < 0 || x >= n || y < 0 || y >= m; }

void set_island(int x, int y, int num) {
	island[x][y] = num;
	for (int i = 0; i < 4; ++i) {
		int nx = x + dx[i], ny = y + dy[i];
		if (OOB(nx, ny) || a[nx][ny] == 0 || chk[nx][ny]) continue;
		chk[nx][ny] = true;
		set_island(nx, ny, num);
	}
}

int find(int a) {
	if (uni[a] == a) return a;
	return uni[a] = find(uni[a]);
}

void make_union(int a, int b) {
	a = find(a), b = find(b);
	if (a <= b) uni[b] = a;
	else uni[a] = b;
}

bool check_all_island() {
	for (int i = 2; i <= lu; ++i) {
		if (find(1) != find(i))
			return false;
	}
	return true;
}

// 현재 위치에서 dir 방향으로 도달가능한 섬까지의 거리 반환
P get_distance(int x, int y, int dir) {
	int nx = x, ny = y, cnt = 0;
	while (!OOB(nx, ny) && !a[nx][ny]) {
		++cnt;
		nx += dx[dir], ny += dy[dir];
	}
	
	if (OOB(nx, ny) || cnt < 2) return { false,-1,-1 };
	return { true, island[nx][ny], cnt };
}

// 섬과 인접한 바다에서 도달가능한 섬까지의 거리를 설정
void set_distance(int x, int y) {
	if (x >= n) return;
	if (a[x][y]) {
		if (y != m) set_distance(x, y + 1);
		else set_distance(x + 1, 0);
		return;
	}

	for (int i = 0; i < 4; ++i) {
		int nx = x + dx[i], ny = y + dy[i], rd = (i+2)%4;
		if (OOB(nx, ny) || !a[nx][ny]) continue;
		auto tmp = get_distance(x, y, rd);
		if (tmp.result) {
			d[island[nx][ny]][tmp.island] = min(d[island[nx][ny]][tmp.island], tmp.cnt);
			d[tmp.island][island[nx][ny]] = min(d[tmp.island][island[nx][ny]], tmp.cnt);
		}
	}

	if (y != m) set_distance(x, y + 1);
	else set_distance(x + 1, 0);
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n >> m;
	for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) cin >> a[i][j];
	for (int i = 1; i <= 7; ++i) uni[i] = i;

	memset(island, 0, sizeof(island));
	for (int i = 1; i < 7; ++i) for (int j = 1; j < 7; ++j) {
		if (i == j) continue;
		d[i][j] = INF;
	}
	
	// 섬 번호 기록
	for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) {
		if (chk[i][j] || a[i][j] == 0) continue;
		chk[i][j] = true;
		set_island(i, j, ++lu);
	}

	set_distance(0, 0);

	vector<triple> mst;
	for (int i = 1; i <= lu; ++i) for (int j = 1; j <= lu; ++j) {
		mst.push_back({ d[i][j], i, j });
	}
	sort(mst.begin(), mst.end());

	// MST
	int ret = 0;
	for (auto& cur : mst) {
		if (find(cur.s) == find(cur.e) || cur.dist == INF) continue;
		make_union(cur.s, cur.e);
		ret += cur.dist;
	}

	if (ret == 0 || !check_all_island()) cout << -1 << '\n';
	else cout << ret << '\n';

	return 0;
}