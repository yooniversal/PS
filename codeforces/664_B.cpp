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
typedef long long ll;

int n, m, y, x;
bool chk[101][101];
vector<pair<int, int>> ans;

void down() {
	int vy = y, vx = x;
	if (!chk[vy][vx]) ans.push_back({ y, x });
	chk[vy][vx] = true;
	while (1) {
		if(vy != n) vy++;
		if (!chk[vy][vx]) {
			ans.push_back({ vy, vx });
			chk[vy][vx] = true;
			//cout << "vy:" << vy << " vx:" << vx << '\n';
			y = vy;
		}
		if (vy == n) {
			break;
		}
		if (ans.size() == n * m) return;
	}
}

void up() {
	int vy = y, vx = x;
	if (!chk[y][x]) ans.push_back({ y, x });
	while (1) {
		if(vy != 1) vy--;
		if (!chk[vy][vx]) {
			ans.push_back({ vy, vx });
			chk[vy][vx] = true;
			y = vy;
		}
		if (vy == 1) {
			break;
		}
		if (ans.size() == n * m) return;
	}
}

void right() {
	int vy = y, vx = x;
	if (!chk[y][x]) ans.push_back({ y, x });
	while (1) {
		if(vx != m) vx++;
		if (!chk[vy][vx]) {
			ans.push_back({ vy, vx });
			chk[vy][vx] = true;
			x = vx;
			break;
		}
		if (vx == m) {
			break;
		}
		if (ans.size() == n * m) return;
	}
}

void left() {
	int vy = y, vx = x;
	if (!chk[y][x]) ans.push_back({ y, x });
	while (1) {
		if(vx != 1) vx--;
		if (!chk[vy][vx]) {
			ans.push_back({ vy, vx });
			chk[vy][vx] = true;
			x = vx;
			break;
		}
		if (vx == 1) {
			break;
		}
		if (ans.size() == n * m) return;
	}
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n >> m >> y >> x;

	down();
	up();
	//cout << ans.size();
	while (1) {
		right();
		down();
		up();
		if (x == m) break;
	}
	while (1) {
		left();
		down();
		up();
		if (x == 1) break;
	}

	for (int i = 0; i < ans.size(); i++) cout << ans[i].first << " " << ans[i].second << '\n';

	return 0;
}