//14500

#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <algorithm>
#define max(a, b) (((a)>(b)) ? (a) : (b))

using namespace std;

int map[505][505], chk[505][505] = { 1, };
int ans, subans;

void block(int x, int y, int n, int m) {

	int sub[19] = { 0, };

	//종료 조건
	if (y > n - 1 || x > m - 1) return;

	if (y <= n - 3 && x <= m - 2) {
		sub[0] = map[y][x + 1] + map[y + 1][x + 1] + map[y + 2][x + 1] + map[y + 2][x];
		sub[1] = map[y][x] + map[y][x + 1] + map[y + 1][x] + map[y + 2][x];
		sub[2] = map[y][x] + map[y + 1][x] + map[y + 2][x] + map[y + 2][x + 1];
		sub[3] = map[y][x] + map[y][x + 1] + map[y + 1][x + 1] + map[y + 2][x + 1];
		sub[4] = map[y + 1][x] + map[y + 1][x + 1] + map[y][x + 1] + map[y + 2][x];
		sub[5] = map[y][x] + map[y + 1][x] + map[y + 1][x + 1] + map[y + 2][x + 1];
		sub[6] = map[y][x] + map[y + 1][x] + map[y + 2][x] + map[y + 1][x + 1];
		sub[7] = map[y + 1][x] + map[y][x + 1] + map[y + 1][x + 1] + map[y + 2][x + 1];
	}
	if (y <= n - 2 && x <= m - 3) {
		sub[8] = map[y][x] + map[y][x + 1] + map[y][x + 2] + map[y + 1][x + 2];
		sub[9] = map[y][x] + map[y + 1][x] + map[y + 1][x + 1] + map[y + 1][x + 2];
		sub[10] = map[y][x] + map[y][x + 1] + map[y][x + 2] + map[y + 1][x];
		sub[11] = map[y + 1][x] + map[y + 1][x + 1] + map[y + 1][x + 2] + map[y][x + 2];
		sub[12] = map[y][x] + map[y][x + 1] + map[y + 1][x + 1] + map[y + 1][x + 2];
		sub[13] = map[y][x + 1] + map[y][x + 2] + map[y + 1][x] + map[y + 1][x + 1];
		sub[14] = map[y][x + 1] + map[y + 1][x] + map[y + 1][x + 1] + map[y + 1][x + 2];
		sub[15] = map[y][x] + map[y][x + 1] + map[y][x + 2] + map[y + 1][x + 1];
	}

	if(y<=n-2 && x<=m-2)
		sub[16] = map[y][x] + map[y + 1][x] + map[y][x + 1] + map[y + 1][x + 1];
	if(y<=n-1 && x<=m-4)
		sub[17] = map[y][x] + map[y][x + 1] + map[y][x + 2] + map[y][x + 3];
	if(y<=n-4 && x<=m-1)
		sub[18] = map[y][x] + map[y + 1][x] + map[y + 2][x] + map[y + 3][x];

	subans = sub[0];
	for (int i = 1; i < 19; i++)
		if (subans < sub[i])
			subans = sub[i];

	ans = max(ans, subans);

	chk[y][x] = 0;
	if (chk[y][x + 1] == 1 && y < n && x+1 < m)
		block(x + 1, y, n, m);
	if (chk[y+1][x + 1] == 1 && y+1 < n && x < m)
		block(x, y + 1, n, m);
}

int main() {

	int n, m;

	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			scanf("%d", &map[i][j]);
			chk[i][j] = 1;
		}

	block(0, 0, n, m);

	printf("%d", ans);

	return 0;

}