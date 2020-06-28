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
bool block[1001][1001];	//���� �� �������� üũ
int dx[4] = { -1, 1, 0, 0 }, dy[4] = { 0, 0, 1, -1 };
deque<check> que;

//������Ʈ ����� BFS �̷�ã�� ������ ����
void bfs(int y, int x) {
	que.push_front(check(y, x));
	chk[y][x] = 1;

	while (!que.empty()) {
		check C = que.back();
		que.pop_back();

		//���� ����
		if (C.y == N - 1 && C.x == M - 1) break;

		for (int i = 0; i < 4; i++) {
			int ny = C.y + dy[i], nx = C.x + dx[i];

			//üũ���� �ʾƵ� �Ǵ� ���̽�
			if (ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
			if (map[ny][nx] == 0 && chk[ny][nx] != 0 && block[ny][nx] == false) continue;
			if (map[ny][nx] == 0 && chk[ny][nx] != 0 && block[C.y][C.x] == true) continue;
			if (map[ny][nx] == 1 && block[C.y][C.x] == true) continue;

			//Ž���� �ȵ� �ڸ�
			if (map[ny][nx] == 0 && chk[ny][nx] == 0) {
				chk[ny][nx] = chk[C.y][C.x] + 1;
				block[ny][nx] = block[C.y][C.x];
				que.push_front(check(ny, nx));
			}
			//Ž���� ������ ���� ���� �ڸ� -> ���� �ȱ��� ���·� ������Ʈ
			else if (map[ny][nx] == 0 && chk[ny][nx] != 0 && block[ny][nx] == true) {
				if (block[C.y][C.x] == false) {
					chk[ny][nx] = chk[C.y][C.x] + 1;
					block[ny][nx] = block[C.y][C.x];
					que.push_front(check(ny, nx));
				}
			}
			//���� ������ ���� ����(C.y, C.x)���� ���� �� ���� ������
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