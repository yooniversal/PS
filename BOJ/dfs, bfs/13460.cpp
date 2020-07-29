//13460
/* NO COMPLETE */

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

typedef long long ll;

int MAP[MAXSIZE][MAXSIZE], MAP2[MAXSIZE][MAXSIZE];
bool chk[MAXSIZE][MAXSIZE];
int ry, rx, by, bx, ey, ex;
int n, m;

int bfsR() {
	int cnt = 1;
	queue<pair<int, int>> q;
	q.push({ ry, rx });
	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		//exit
		if (y == ey && x == ex) {
			return MAP[y][x];
		}
		if (cnt > 10) {
			cout << "-1";
			exit(1);
		}
		if (MAP[y][x] != cnt - 1 && cnt>1) continue;

		//cout << "y:" << y << " x:" << x << '\n';

		//left
		int ly = y, lx = x;
		while (1) {
			lx += -1;
			if (MAP[ly][lx] != 0) {
				//cout << "ly:" << ly << " lx:" << lx << '\n';
				break;
			}
			if(MAP[ly][lx] == 0) MAP[ly][lx] = cnt;
			if (ly == ey && lx == ex) return MAP[ly][lx];
		}
		lx += 1; q.push({ ly, lx });
		//right
		int ry = y, rx = x;
		while (1) {
			rx += 1;
			if (MAP[ry][rx] != 0) break;
			if (MAP[ry][rx] == 0) MAP[ry][rx] = cnt;
			if (ry == ey && rx == ex) return MAP[ry][rx];
		}
		rx += -1; q.push({ ry, rx });
		//up
		int uy = y, ux = x;
		while (1) {
			uy += -1;
			if (MAP[uy][ux] != 0) break;
			if (MAP[uy][ux] == 0) MAP[uy][ux] = cnt;
			if (uy == ey && ux == ex) return MAP[uy][ux];
		}
		uy += 1; q.push({ uy, ux });
		//down
		int dy = y, dx = x;	
		while (1) {
			dy += 1;
			if (MAP[dy][dx] != 0) break;
			if (MAP[dy][dx] == 0) MAP[dy][dx] = cnt;
			if (dy == ey && dx == ex) return MAP[dy][dx];
		}
		dy += -1; q.push({ dy, dx });

		cnt++;
	}
}

int bfsB() {
	int cnt = 0;
	queue<pair<int, int>> q;
	q.push({ by, bx });
	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		//exit
		if (y == ey && x == ex) {
			return MAP2[y][x];
		}
		if (cnt > 10) {
			return -1;
		}
		if (MAP2[y][x] != cnt - 1 && cnt > 1) continue;

		//left
		int ly = y, lx = x;
		while (1) {
			lx += -1;
			if (MAP2[ly][lx] != 0) {
				break;
			}
			if (MAP2[ly][lx] == 0) MAP2[ly][lx] = cnt;
			if (ly == ey && lx == ex) return MAP[ly][lx];
		}
		lx += 1; q.push({ ly, lx });
		//right
		int ry = y, rx = x;
		while (1) {
			rx += 1;
			if (MAP2[ry][rx] != 0) break;
			if (MAP2[ry][rx] == 0) MAP2[ry][rx] = cnt;
			if (ry == ey && rx == ex) return MAP2[ry][rx];
		}
		rx += -1; q.push({ ry, rx });
		//up
		int uy = y, ux = x;
		while (1) {
			uy += -1;
			if (MAP2[uy][ux] != 0) break;
			if (MAP2[uy][ux] == 0) MAP2[uy][ux] = cnt;
			if (uy == ey && ux == ex) return MAP2[uy][ux];
		}
		uy += 1; q.push({ uy, ux });
		//down
		int dy = y, dx = x;
		while (1) {
			dy += 1;
			if (MAP2[dy][dx] != 0) break;
			if (MAP2[dy][dx] == 0) MAP[dy][dx] = cnt;
			if (dy == ey && dx == ex) return MAP2[dy][dx];
		}
		dy += -1; q.push({ dy, dx });

		cnt++;
	}
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n >> m;
	
	//make map1
	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		for (int j = 0; j < m; j++) {
			if (s[j] == '#') MAP[i][j] = -1;
			else if (s[j] == 'R') {
				ry = i;
				rx = j;
				//MAP[ry][rx] = -2;
				//MAP2[ry][rx] = -2;
			}
			else if (s[j] == 'B') {
				by = i;
				bx = j;
				//MAP[by][bx] = -2;
				//MAP2[by][bx] = -2;
			}
			else if (s[j] == 'O') {
				ey = i;
				ex = j;
			}
		}
	}

	//make map2
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			MAP2[i][j] = MAP[i][j];
		}
	}

	int R = bfsR();
	int B = bfsB();
	cout << "R:" << R << " B:" << B << '\n';

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			if (MAP2[i][j] != -1) cout << MAP2[i][j];
			else cout << '#';
		cout << '\n';
	}

	//answer
	if (B > 0 && B <= R) cout << "-1";
	else {
		cout << R;
	}

	return 0;
}