//7576

#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <vector>
#include <deque>
#include <cmath>
#include <algorithm>
using namespace std;

int origin[1005][1005], map[1005][1005];
bool chk[1005][1005];
int row, col;

void copy() {
	for (int i = 1; i <= row; i++)
		for (int j = 1; j <= col; j++)
			origin[i][j] = map[i][j];
}

bool isfull() {
	for (int i = 1; i <= row; i++)
		for (int j = 1; j <= col; j++)
			if (map[i][j] == 0) return false;
	return true;
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int dy[4] = { -1,1,0,0 }, dx[4] = { 0,0,1,-1 };
	int day=0, key, psize;
	deque<pair<int, int>> yx, checked, pre;

	cin >> col >> row;
	for (int i = 1; i <= row; i++)
		for (int j = 1; j <= col; j++) {
			cin >> origin[i][j];
			map[i][j] = origin[i][j];
			if (origin[i][j] == 1) {
				chk[i][j] = true;
				pre.push_front(make_pair(i, j));
			}
		}

	while (isfull() == false) {
		key = 0;
		psize = pre.size();
		while (psize--) {
			//익은 토마토 위치 불러오기
			int hy = pre.back().first;
			int hx = pre.back().second;
			pre.pop_back();

			if (origin[hy][hx] == 1) {
				//익은 토마토로부터 사방으로 
				for (int i = 0; i < 4; i++) {
					int ny = hy + dy[i]; int nx = hx + dx[i];
					if (nx<1 || nx>col || ny<1 || ny>row || origin[ny][nx] == -1 || chk[ny][nx] == true) continue;
					if (origin[ny][nx] == 0) {
						chk[ny][nx] = true;
						map[ny][nx] = 1;
						key = 1;
						pre.push_front(make_pair(ny, nx));
						yx.push_front(make_pair(ny, nx));
					}
				}
				checked.push_front(make_pair(hy, hx));
			}
		}

		//변경된 부분이 없으면
		if (key == 0) {
			cout << "-1";
			return 0;
		}

		//origin <- map
		while (!checked.empty()) {
			origin[checked.back().first][checked.back().second] = -1;
			checked.pop_back();
		}
		while(!yx.empty()) {
			origin[yx.back().first][yx.back().second] = 1;
			yx.pop_back();
		}

		day++;
	}

	cout << day;

	return 0;
}