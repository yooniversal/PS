//13460
/* NON-COMPLETE */

#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <cmath>
#include <algorithm>
#include <map>
using namespace std;
#define MAXSIZE 11

struct rb {
	int ry, rx, by, bx;

	rb(int a, int b, int c, int d) : ry(a), rx(b), by(c), bx(d) {}
};

typedef long long ll;

int MAP[MAXSIZE][MAXSIZE], MAP2[MAXSIZE][MAXSIZE];
bool chk[MAXSIZE][MAXSIZE];
int ry, rx, by, bx, ey, ex;
int n, m, ddy[4] = { -1, 1, 0, 0 }, ddx[4] = { 0, 0, 1, -1 };

pair<int, bool> bfs() {
	int cnt = 1;
	queue<rb> q;
	q.push({ ry, rx, by, bx });
	while (!q.empty()) {
		int ry = q.front().ry, rx = q.front().rx;
		int by = q.front().by, bx = q.front().bx;
		q.pop();

		chk[ry][rx] = true;
		chk[by][bx] = true;

		//종료 조건
		//R, B가 동시에 들어갔을 때
		if ((ry == ey && rx == ex) && (by == ey && bx == ex)) {
			cout << "-1";
			exit(1);
		}
		//R이 먼저 들어갔을 때
		if (ry == ey && rx == ex) return { MAP[ey][ex], true };
		//B가 먼저 들어갔을 때
		if (by == ey && bx == ex) return { MAP[ey][ex], false };
		//시간 초과
		if (cnt > 10) {
			cout << "-1";
			exit(1);
		}
		//if (MAP[y][x] != cnt - 1 && cnt>1) continue;

		int ly, lx, rry, rrx, uy, ux, dy, dx;
		int ly2, lx2, rry2, rrx2, uy2, ux2, dy2, dx2;
		ly = rry = uy = dy = ry;
		lx = rrx = ux = dx = rx;
		ly2 = rry2 = uy2 = dy2 = by;
		lx2 = rrx2 = ux2 = dx2 = bx;
		//R 이동 가능여부 탐색
		bool canmove = false;
		for (int i = 0; i < 4; i++) {
			int hy = ry + ddy[i], hx = rx + ddx[i];
			if (hy < 0 || hy >= n || hx < 0 || hx >= m) continue;
			if (chk[hy][hx] || MAP[hy][hx]) continue;
			canmove = true;
		}
		//이동 가능
		if (canmove) {
			//left
			ly = ry, lx = rx;
			while (1) {
				if (MAP[ly][lx-1] != 0) break; //이미 지나간 자리
				if (chk[ly][lx-1]) break;	//B의 위치
				MAP[ly][lx-1] = cnt;
				if (ly == ey && lx - 1 == ex) return { MAP[ly][lx - 1], true }; //목표 지점
				lx += -1;
			}
			//rq.push({ ly, lx });
			//right
			rry = ry, rrx = rx;
			while (1) {
				if (MAP[rry][rrx+1] != 0) break;
				if (MAP[rry][rrx+1] == 0) MAP[rry][rrx+1] = cnt;
				if (rry == ey && rrx + 1 == ex) return { MAP[rry][rrx + 1], true };
				rrx += 1;
			}
			//q.push({ ry, rx });
			//up
			uy = ry, ux = rx;
			while (1) {
				if (MAP[uy-1][ux] != 0) break;
				if (MAP[uy-1][ux] == 0) MAP[uy-1][ux] = cnt;
				if (uy - 1 == ey && ux == ex) return { MAP[uy - 1][ux],true };
				uy += -1;
			}
			//rq.push({ uy, ux });
			//down
			dy = ry, dx = rx;
			while (1) {
				if (MAP[dy+1][dx] != 0) break;
				if (MAP[dy+1][dx] == 0) MAP[dy+1][dx] = cnt;
				if (dy + 1 == ey && dx == ex) return { MAP[dy + 1][dx], true };
				dy += 1;
			}
			//rq.push({ dy, dx });
		}

		//B 이동 가능여부 탐색
		bool canmove2 = false;
		for (int i = 0; i < 4; i++) {
			int hy = by + ddy[i], hx = bx + ddx[i];
			if (hy < 0 || hy >= n || hx < 0 || hx >= m) continue;
			if (chk[hy][hx] || MAP[hy][hx]) continue;
			canmove2 = true;
		}
		if (canmove2) {
			//left
			ly2 = by, lx2 = bx;
			while (1) {
				if (MAP[ly2][lx2 - 1] != 0) break; //이미 지나간 자리
				if (chk[ly2][lx2 - 1]) break;	//B의 위치
				MAP[ly2][lx2 - 1] = cnt;
				if (ly2 == ey && lx2 - 1 == ex) return { MAP[ly2][lx2 - 1],false }; //목표 지점
				lx2 += -1;
			}
			//rq.push({ ly, lx });
			//right
			rry2 = ry, rrx2 = rx;
			while (1) {
				if (MAP[rry2][rrx2 + 1] != 0) break;
				if (MAP[rry2][rrx2 + 1] == 0) MAP[rry2][rrx2 + 1] = cnt;
				if (rry2 == ey && rrx2 + 1 == ex) return { MAP[rry2][rrx2 + 1], false };
				rrx2 += 1;
			}
			//q.push({ ry, rx });
			//up
			uy2 = ry, ux2 = rx;
			while (1) {
				if (MAP[uy2 - 1][ux2] != 0) break;
				if (MAP[uy2 - 1][ux2] == 0) MAP[uy2 - 1][ux2] = cnt;
				if (uy2 - 1 == ey && ux2 == ex) return { MAP[uy2 - 1][ux2], false };
				uy2 += -1;
			}
			//rq.push({ uy, ux });
			//down
			dy2 = ry, dx2 = rx;
			while (1) {
				if (MAP[dy2 + 1][dx2] != 0) break;
				if (MAP[dy2 + 1][dx2] == 0) MAP[dy2 + 1][dx2] = cnt;
				if (dy2 + 1 == ey && dx2 == ex) return { MAP[dy2 + 1][dx2], false };
				dy2 += 1;
			}
			//rq.push({ dy, dx });
		}

		//R이 이동못했다면
		if (!canmove) {
			//R 이동 가능여부 탐색
			bool canmove3 = false;
			for (int i = 0; i < 4; i++) {
				int hy = ry + ddy[i], hx = rx + ddx[i];
				if (hy < 0 || hy >= n || hx < 0 || hx >= m) continue;
				if (chk[hy][hx] || MAP[hy][hx]) continue;
				canmove3 = true;
			}
			//이동 가능
			if (canmove3) {
				//left
				ly = ry, lx = rx;
				while (1) {
					if (MAP[ly][lx - 1] != 0) break; //이미 지나간 자리
					if (chk[ly][lx - 1]) break;	//B의 위치
					MAP[ly][lx - 1] = cnt;
					if (ly == ey && lx - 1 == ex) return { MAP[ly][lx - 1], true }; //목표 지점
					lx += -1;
				}
				//rq.push({ ly, lx });
				//right
				rry = ry, rrx = rx;
				while (1) {
					if (MAP[rry][rrx + 1] != 0) break;
					if (MAP[rry][rrx + 1] == 0) MAP[rry][rrx + 1] = cnt;
					if (rry == ey && rrx + 1 == ex) return { MAP[rry][rrx + 1], true };
					rrx += 1;
				}
				//q.push({ ry, rx });
				//up
				uy = ry, ux = rx;
				while (1) {
					if (MAP[uy - 1][ux] != 0) break;
					if (MAP[uy - 1][ux] == 0) MAP[uy - 1][ux] = cnt;
					if (uy - 1 == ey && ux == ex) return { MAP[uy - 1][ux], true };
					uy += -1;
				}
				//rq.push({ uy, ux });
				//down
				dy = ry, dx = rx;
				while (1) {
					if (MAP[dy + 1][dx] != 0) break;
					if (MAP[dy + 1][dx] == 0) MAP[dy + 1][dx] = cnt;
					if (dy + 1 == ey && dx == ex) return { MAP[dy + 1][dx], true };
					dy += 1;
				}
				//rq.push({ dy, dx });
			}
		}

		/*cout << "************" << '\n';
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++)
				if (MAP[i][j] != -1) cout << MAP[i][j];
				else cout << '#';
			cout << '\n';
		}*/

		chk[ry][rx] = false;
		chk[by][bx] = false;
		chk[ly][lx] = true; chk[ly2][lx2] = true;
		chk[rry][rrx] = true; chk[rry2][rrx2] = true;
		chk[uy][ux] = true; chk[uy2][ux2] = true;
		chk[dy][dx] = true; chk[dy2][dx2] = true;

		q.push({ ly, lx, ly2, lx2 });
		q.push({ rry, rrx, rry2, rrx2 });
		q.push({ uy, ux, uy2, ux2 });
		q.push({ dy, dx, dy2, dx2 });

		cnt++;
	}
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n >> m;
	
	//make map
	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		for (int j = 0; j < m; j++) {
			if (s[j] == '#') MAP[i][j] = -1;
			else if (s[j] == 'R') {
				ry = i;
				rx = j;
			}
			else if (s[j] == 'B') {
				by = i;
				bx = j;
			}
			else if (s[j] == 'O') {
				ey = i;
				ex = j;
			}
		}
	}

	pair<int, bool> ans = bfs();

	/*for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			if (MAP[i][j] != -1) cout << MAP[i][j];
			else cout << '#';
		cout << '\n';
	}*/

	//answer
	if (ans.second) cout << "ans:" << ans.first;
	else cout << "-1, false";

	return 0;
}