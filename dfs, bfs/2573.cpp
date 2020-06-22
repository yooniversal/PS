//2573

#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

int arr[301][301], chk[301][301], mimi[301][301];
int dx[] = { -1, 1, 0, 0 }, dy[] = { 0, 0, 1, -1 };
int m, n, chunk;

void dfs(int x, int y) {
	chk[x][y] = 1;

	//종료 조건
	if (x < 0 || x > n - 1 || y < 0 || y > m - 1) return;
	else {
		if (arr[x + 1][y] == 0 && arr[x - 1][y] == 0 && arr[x][y - 1] == 0 && arr[x][y + 1] == 0)
			return;
		else {
			if (arr[x + 1][y] != 0 && chk[x + 1][y] == 0) dfs(x + 1, y);
			if (arr[x - 1][y] != 0 && chk[x - 1][y] == 0) dfs(x - 1, y);
			if (arr[x][y - 1] != 0 && chk[x][y - 1] == 0) dfs(x, y - 1);
			if (arr[x][y + 1] != 0 && chk[x][y + 1] == 0) dfs(x, y + 1);
		}
	}
}

void melt() {
	for (int y = 0; y < n; y++)
		for (int x = 0; x < m; x++)
			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i], ny = y + dy[i];
				if (nx >= 0 && nx < m && ny >= 0 && ny < n)
					if (arr[ny][nx] == 0 && arr[y][x] != 0) mimi[y][x]++;
			}

	for (int y = 0; y < n; y++)
		for (int x = 0; x < m; x++) {
			arr[y][x] -= mimi[y][x];
			if (arr[y][x] < 0) arr[y][x] = 0;
		}

}

bool isZero() {
	for (int y = 0; y < n; y++)
		for (int x = 0; x < m; x++)
			if (arr[y][x] != 0)
				return false;
	return true;
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int year = 0;

	//input
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> arr[i][j];

	//덩어리 개수가 2 미만이면 진행(chunk = 0, 1)
	while (chunk<2) {
		memset(chk, 0, sizeof(chk));
		memset(mimi, 0, sizeof(mimi));
		chunk = 0;

		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				if (arr[i][j] != 0 && chk[i][j] == 0) {
					dfs(i, j);
					chunk++;	//chunk는 덩어리의 개수
				}
		if (chunk < 2) {
			melt();

			year++;
		}
		//덩어리가 2이상이면 loop 탈출
		else 
			break;

		//모든 빙하의 높이가 0이면 중단
		if (isZero()) {
			cout << "0";
			return 0;
		}
	}

	cout << year;

	return 0;
}