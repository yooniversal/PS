//4677

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

char map[101][101];
bool chk[101][101];
int dy[8] = { -1,1,0,0,1,1,-1,-1}, dx[8] = { 0,0,1,-1,1,-1,1,-1 }, row, col;
int chunk;

void dfs(int y, int x) {

	//종료 조건
	if(chk[y][x] == false) return;

	chk[y][x] = false;

	for (int i = 0; i < 8; i++) {
		int ny = y + dy[i], nx = x + dx[i];	
		if (ny<0 || ny>row - 1 || nx<0 || nx>col - 1 || chk[ny][nx] == false) continue;
		dfs(ny, nx);
	}
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	while (1) {
		chunk = 0;

		cin >> row >> col;
		if (row == 0 || col == 0) break;

		for (int i = 0; i < row; i++)
			for (int j = 0; j < col; j++) {
				cin >> map[i][j];
				if (map[i][j] == '@') chk[i][j] = true;
			}

		for (int i = 0; i < row; i++)
			for (int j = 0; j < col; j++)
				if (chk[i][j] == true) {
					dfs(i, j);
					chunk++;
				}

		cout << chunk << '\n';

		memset(chk, false, sizeof(chk));
	}
	

	return 0;
}