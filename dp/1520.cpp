//1520

#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <vector>
#include <deque>
#include <queue>
#include <cmath>
#include <algorithm>
#include <functional>
using namespace std;

int dp[501][501], map[501][501];
int dy[4] = { -1, 1, 0, 0 }, dx[4] = { 0, 0, 1, -1 };
int row, col;

int dfs(int y, int x) {

	if (y == row - 1 && x == col - 1) return 1;
	
	if (dp[y][x] != -1) return dp[y][x];
	dp[y][x] = 0;

	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i], nx = x + dx[i];
		if (ny<0 || ny>row - 1 || nx<0 || nx>col - 1 || map[y][x] <= map[ny][nx]) continue;
		if (map[y][x] > map[ny][nx]) dp[y][x] += dfs(ny, nx);
	}

	return dp[y][x];
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> row >> col;

	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++) {
			cin >> map[i][j];
			dp[i][j] = -1;
		}

	cout << dfs(0, 0);

	return 0;
}