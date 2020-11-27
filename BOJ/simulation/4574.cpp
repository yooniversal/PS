//4574
#include <bits/stdc++.h>
using namespace std;
#define INF 1000000000
#define MAX 10000001
#define MOD 1000000007
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

bool domino[10][10], row[10][10], col[10][10], block[10][10], finish;
int a[10][10], dx[] = { -1,1,0,0 }, dy[] = { 0,0,1,-1 };
int testcase;

ii Where(string s) {
	return { s[0] - 'A', s[1] - '1' }; //row, col
}

//블럭 번호
int B(string s) {
	int row = s[0] - 'A', col = s[1] - '1';
	return (row / 3) * 3 + col / 3;
}

int B(int x, int y) { return (x / 3) * 3 + y / 3; }

bool OOB(int x, int y) { return x < 0 || x >= 9 || y < 0 || y >= 9; }

void solve(int x, int y, int remain) {
	//완성됐다면 종료
	if (finish) return;

	//완성 여부 체크
	if (x==8 && y==8) {
		finish = remain == 0 ? true : false;
		if (finish) {
			cout << "Puzzle " << ++testcase << '\n';
			for (int i = 0; i < 9; ++i) {
				for (int j = 0; j < 9; ++j)
					cout << a[i][j];
				cout << '\n';
			}
		}
		return;
	}

	//현재 위치에 이미 숫자가 적혀 있을 경우
	if (a[x][y] != 0) {
		if (OOB(x, y + 1)) solve(x + 1, 0, remain);
		else solve(x, y + 1, remain);
		return;
	}

	for (int num = 1; num <= 9; ++num) {
		if (row[x][num] || col[y][num] || block[B(x, y)][num]) continue;
		for (int i = 0; i < 4; ++i) {
			int nx = x + dx[i], ny = y + dy[i];
			if (OOB(nx, ny) || a[nx][ny]) continue;
			for (int nextNum = 1; nextNum <= 9; ++nextNum) {
				if (row[nx][nextNum] || col[ny][nextNum] || block[B(nx, ny)][nextNum] || domino[num][nextNum]) continue;
				row[x][num] = col[y][num] = block[B(x, y)][num] = true;
				row[nx][nextNum] = col[ny][nextNum] = block[B(nx, ny)][nextNum] = true;
				domino[num][nextNum] = domino[nextNum][num] = true;
				a[x][y] = num; a[nx][ny] = nextNum;

				if (OOB(x, y + 1)) solve(x + 1, 0, remain-2);
				else solve(x, y + 1, remain-2);
				if (finish) return;

				row[x][num] = col[y][num] = block[B(x, y)][num] = false;
				row[nx][nextNum] = col[ny][nextNum] = block[B(nx, ny)][nextNum] = false;
				domino[num][nextNum] = domino[nextNum][num] = false;
				a[x][y] = a[nx][ny] = 0;
			}
		}
	}
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	while (1) {
		finish = false;
		for (int i = 0; i < 10; ++i) for (int j = 0; j < 10; ++j) {
			domino[i][j] = row[i][j] = col[i][j] = block[i][j] = a[i][j] = 0;
		}

		int n; cin >> n;
		if (n == 0) break;
		for (int i = 0; i < n; ++i) {
			int u, v; string lu, lv;
			cin >> u >> lu >> v >> lv;
			domino[u][v] = domino[v][u] = true;
			a[Where(lu).first][Where(lu).second] = u;
			a[Where(lv).first][Where(lv).second] = v;
			row[Where(lu).first][u] = row[Where(lv).first][v] = true;
			col[Where(lu).second][u] = col[Where(lv).second][v] = true;
			block[B(lu)][u] = block[B(lv)][v] = true;
		}

		for (int i = 1; i <= 9; ++i) {
			string s; cin >> s;
			a[Where(s).first][Where(s).second] = i;
			row[Where(s).first][i] = col[Where(s).second][i] = true;
			block[B(s)][i] = true;
		}

		//도미노는 같은 쌍의 수를 가질 수 없음
		for (int i = 1; i <= 9; ++i) domino[i][i] = true;

		solve(0, 0, 81-(n*2+9));
	}

	return 0;
}