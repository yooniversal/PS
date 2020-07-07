//7579

#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <vector>
#include <deque>
#include <cmath>
#include <algorithm>
using namespace std;

int origin[101][101][101], map[101][101][101];
bool chk[101][101][101];
int row, col, high;

//인자가 3개 이상이면 pair로는 불가능
//구조체로 선언해서 이용하자
struct triple {
	int h;
	int r;
	int c;

	//생성자를 만들어 줌으로써 triple T(a, b, c) 의 초기화가 가능해졌다
	triple(int a, int b, int c) : h(a), r(b), c(c)
	{
	}
};

bool isfull() {
	for (int h = 1; h <= high; h++)
		for (int i = 1; i <= row; i++)
			for (int j = 1; j <= col; j++)
				if (map[h][i][j] == 0) return false;
	return true;
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int dy[6] = { -1,1,0,0,0,0 }, dx[6] = { 0,0,1,-1,0,0 }, dz[6] = { 0,0,0,0, -1, 1 };
	int day = 0, key, psize;
	deque<triple> yx, checked, pre;	//pair -> triple

	cin >> col >> row >> high;
	for (int h = 1; h <= high; h++) {
		for (int i = 1; i <= row; i++)
			for (int j = 1; j <= col; j++) {
				cin >> origin[h][i][j];
				map[h][i][j] = origin[h][i][j];
				if (origin[h][i][j] == 1) {
					chk[h][i][j] = true;
					pre.push_front(triple(h, i, j));	//초기화 및 push 예
				}
			}
	}

	while (isfull() == false) {
		key = 0;
		psize = pre.size();
		while (psize--) {
			//익은 토마토 위치 불러오기
			triple T = pre.back();		//구조체로 위치 참조할 땐 이렇게
			pre.pop_back();

			if (origin[T.h][T.r][T.c] == 1) {
				//익은 토마토로부터 사방으로 
				
				for (int i = 0; i < 6; i++) {
					int ny = T.r + dy[i]; int nx = T.c + dx[i]; int nz = T.h + dz[i];
					if (nz<1 || nz>high || nx<1 || nx>col || ny<1 || ny>row || origin[nz][ny][nx] == -1 || chk[nz][ny][nx] == true) continue;
					if (origin[nz][ny][nx] == 0) {
						chk[nz][ny][nx] = true;
						map[nz][ny][nx] = 1;
						key = 1;
						pre.push_front(triple(nz, ny, nx));
						yx.push_front(triple(nz, ny, nx));
					}
				}
				checked.push_front(triple(T.h, T.r, T.c));
			}
		}

		//변경된 부분이 없으면
		if (key == 0) {
			cout << "-1";
			return 0;
		}

		//origin <- map
		while (!checked.empty()) {
			triple loc = checked.back();
			origin[loc.h][loc.r][loc.c] = -1;
			checked.pop_back();
		}
		while (!yx.empty()) {
			triple loc = yx.back();
			origin[loc.h][loc.r][loc.c] = 1;
			yx.pop_back();
		}

		day++;
	}

	cout << day;

	return 0;
}