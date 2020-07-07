//7562
//미로찾기 BFS와 알고리즘은 동일
//dy, dx를 나이트 이동 가능 범위로 맞춰주면 된다

#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <vector>
#include <deque>
#include <queue>
#include <cmath>
#include <algorithm>
using namespace std;

int ey, ex, siz;
int map[301][301], dy[] = {2, 2, -2, -2, 1, 1, -1, -1}, dx[] = {1, -1, 1, -1, 2, -2, 2, -2};
queue<pair<int, int>> q;

void bfs(int y, int x) {
	q.push({ y, x });
	while (!q.empty()) {
		int hy = q.front().first, hx = q.front().second;
		q.pop();
		if (hy == ey && hx == ex) break;
		for (int i = 0; i < 8; i++) {
			int ny = hy + dy[i], nx = hx + dx[i];
			if (ny < 0 || ny >= siz || nx < 0 || nx >= siz || map[ny][nx] != 0) continue;
			map[ny][nx] = map[hy][hx] + 1;
			q.push({ ny, nx });
		}
	}
	cout << map[ey][ex] << '\n';
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int t, sy, sx;

	cin >> t;
	while (t--) {
		cin >> siz;
		cin >> sy >> sx;
		cin >> ey >> ex;
		bfs(sy, sx);

		while (!q.empty()) q.pop();
		memset(map, 0, sizeof(map));
	}

	return 0;
}