//2178

#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <vector>
#include <deque>
#include <cmath>
#include <algorithm>
using namespace std;

int N, M;
int map[101][101], chk[101][101];
int dx[4] = { -1, 1, 0, 0 }, dy[4] = { 0, 0, 1, -1 };
deque<pair<int, int>> que;

//bfs�� ���X
//������ �Ÿ��� chk�� ������Ʈ ���ش�
void bfs(int y, int x) {
	//ó�� ���� push �� chk ������Ʈ
	que.push_front(make_pair(y, x));
	chk[y][x] = 1;

	//ť�� ���� ������ ��� ����
	while (!que.empty()) {
		int hy = que.back().first;
		int hx = que.back().second;
		que.pop_back();

		if (hy == N - 1 && hx == M - 1) break;

		//������� Ž��
		for (int i = 0; i < 4; i++) {
			int ny = hy + dy[i], nx = hx + dx[i];
			if (ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
			if (map[ny][nx] == 1 && chk[ny][nx] == 0) {	//�ƻ� �ȵ� ���̸� chk ������Ʈ �� push
				chk[ny][nx] = chk[hy][hx] + 1;			//���� chk�� �������ذ� �ִ� �Ÿ�
				que.push_front(make_pair(ny, nx));
			}
		}
	}

	cout << chk[N-1][M-1];
	return;
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

	return 0;
}