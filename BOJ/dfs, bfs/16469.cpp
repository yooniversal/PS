//16469
#include <bits/stdc++.h>
using namespace std;
#define INF 1000000000
#define MAX 605
#define MOD 1000000007
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

int dx[] = { -1,1,0,0 }, dy[] = { 0,0,1,-1 };
int r, c;
bool wall[101][101];

bool OOB(int x, int y) {
	if (x < 0 || x >= r || y < 0 || y >= c) return true;
	return false;
}

void BFS(int x, int y, vvi& a) {
	queue<ii> q;
	q.push({ x, y });
	a[x][y] = 1;
	while (!q.empty()) {
		int x = q.front().first, y = q.front().second; q.pop();
		for (int i = 0; i < 4; ++i) {
			int nx = x + dx[i], ny = y + dy[i];
			if (OOB(nx, ny)) continue;
			if (wall[nx][ny]) continue;
			if (a[nx][ny]) continue;
			a[nx][ny] = a[x][y] + 1;
			q.push({ nx, ny });
		}
	}
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> r >> c;
	vvi A(r, vi(c, 0)), B(r, vi(c, 0)), C(r, vi(c, 0));
	for (int i = 0; i < r; ++i) {
		string s; cin >> s;
		for (int j = 0; j < c; ++j)
			if (s[j] == '1') wall[i][j] = true;
	}
	int x, y;
	cin >> x >> y; BFS(x-1, y-1, A);
	cin >> x >> y; BFS(x-1, y-1, B);
	cin >> x >> y; BFS(x-1, y-1, C);

	int T = INF, cnt = 0;
	for (int i = 0; i < r; ++i) {
		for (int j = 0; j < c; ++j) {
			if (!A[i][j] || !B[i][j] || !C[i][j]) continue;
			if (T == max(A[i][j], max(B[i][j], C[i][j]))-1) ++cnt;
			else if(T > max(A[i][j], max(B[i][j], C[i][j]))-1){
				T = max(A[i][j], max(B[i][j], C[i][j]))-1;
				cnt = 1;
			}
		}
	}
	if (T != INF) cout << T << '\n' << cnt << '\n';
	else cout << -1 << '\n';

	return 0;
}