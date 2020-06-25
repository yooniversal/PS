//2589

#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <vector>
#include <deque>
#include <cmath>
#include <algorithm>
using namespace std;

int row, col;
bool check[51][51], visit[51][51];
int dy[4] = { -1,1,0,0 }, dx[4] = { 0,0,1,-1 }, map[51][51];
vector<long long> ans;
deque<pair<int, int>> que;

void bfs(int y, int x) {
	que.push_front(make_pair(y, x));
	visit[y][x] = true;

	while (!que.empty()) {
		int hy = que.back().first;
		int hx = que.back().second;
		que.pop_back();

		//종료 조건
		for (int i = 0; i < 4; i++) {
			int ny = hy + dy[i], nx = hx + dx[i];
			if (ny < 1 || ny > row || nx < 1 || nx > col) continue;
			if (!(check[ny][nx] == true || visit[ny][nx] == true)) break;		//갈 곳이 있으면
			if (i == 3 && (check[ny][nx] == true || visit[ny][nx] == true)) {	//더 이상 갈 곳이 없으면
				long long m = 0;
				for (int i = 1; i <= row; i++)
					for (int j = 1; j <= col; j++)
						if (m < map[i][j] && check[i][j] == false) m = map[i][j];	//최댓값 반환
				ans.push_back(m);													//해당 케이스에서 최댓값 저장
			}
		}

		visit[hy][hx] = true;

		for (int i = 0; i < 4; i++) {
			int ny = hy + dy[i]; int nx = hx + dx[i];
			if (ny < 1 || ny > row || nx<1 || nx>col) continue;
			if (check[ny][nx] == false && visit[ny][nx] == false && map[ny][nx] == 0) {
				map[ny][nx] = map[hy][hx] + 1;
				que.push_front(make_pair(ny, nx));
			}
		}
	}
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	string str;

	cin >> row >> col;
	//맵 만들기
	for (int i = 1; i <= row; i++) {
		cin >> str;
		for (int j = 1; j <= col; j++)
			if (str[j-1] == 'W') check[i][j] = true;
			else check[i][j] = false;
	}
	
	//PROCESS
	//모든 점을 시작점으로 잡고 이동가능한 길을 모두 이동하면서
	//그때그때 나오는 최댓값을 저장한다
	for (int y = 1; y <= row; y++)
		for (int x = 1; x <= col; x++)
			if (check[y][x] == false) {
				bfs(y, x);
				memset(map, 0, sizeof(map));
				memset(visit, false, sizeof(visit));
			}

	//저장한 케이스별 최댓값 중 최댓값이 정답
	long long maxx = 0;
	for (int i = 0; i < ans.size(); i++) {
		if (maxx < ans[i]) maxx = ans[i];
	}

	cout << maxx;

	return 0;
}