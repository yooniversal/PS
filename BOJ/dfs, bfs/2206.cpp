//2206

#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <vector>
#include <deque>
#include <cmath>
#include <algorithm>
using namespace std;

struct check {
	int y;
	int x;

	check(int a, int b) : y(a), x(b)
	{
	}
};

int N, M;
int map[1001][1001], chk[1001][1001];
bool block[1001][1001];	//벽을 깬 상태인지 체크
int dx[4] = { -1, 1, 0, 0 }, dy[4] = { 0, 0, 1, -1 };
deque<check> que;

//업데이트 방식은 BFS 미로찾기 문제와 같음
void bfs(int y, int x) {
	que.push_front(check(y, x));
	chk[y][x] = 1;

	while (!que.empty()) {
		check C = que.back();
		que.pop_back();

		//종료 조건
		if (C.y == N - 1 && C.x == M - 1) break;

		for (int i = 0; i < 4; i++) {
			int ny = C.y + dy[i], nx = C.x + dx[i];

			//체크하지 않아도 되는 케이스
			if (ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
			if (map[ny][nx] == 0 && chk[ny][nx] != 0 && block[ny][nx] == false) continue;
			if (map[ny][nx] == 0 && chk[ny][nx] != 0 && block[C.y][C.x] == true) continue;
			if (map[ny][nx] == 1 && block[C.y][C.x] == true) continue;

			//탐색이 안된 자리
			if (map[ny][nx] == 0 && chk[ny][nx] == 0) {
				chk[ny][nx] = chk[C.y][C.x] + 1;
				block[ny][nx] = block[C.y][C.x];
				que.push_front(check(ny, nx));
			}
			//탐색이 됐으나 벽을 깨온 자리 -> 벽을 안깨온 상태로 업데이트
			else if (map[ny][nx] == 0 && chk[ny][nx] != 0 && block[ny][nx] == true) {
				if (block[C.y][C.x] == false) {
					chk[ny][nx] = chk[C.y][C.x] + 1;
					block[ny][nx] = block[C.y][C.x];
					que.push_front(check(ny, nx));
				}
			}
			//벽이 있지만 현재 상태(C.y, C.x)에서 벽을 깬 적이 없으면
			if (map[ny][nx] == 1 && block[C.y][C.x] == false) {
				chk[ny][nx] = chk[C.y][C.x] + 1;
				block[ny][nx] = true;
				que.push_front(check(ny, nx));
			}
		}
	}
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	string arr;

	//input
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> arr;
		for (int j = 0; j < M; j++)
			map[i][j] = arr[j] - '0';
	}

	bfs(0, 0);

	if (chk[N - 1][M - 1] != 0)
		cout << chk[N - 1][M - 1];
	else
		cout << "-1";
	
	return 0;
}