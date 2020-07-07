//2667

#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <vector>
#include <deque>
#include <cmath>
#include <algorithm>
using namespace std;

int row, col, block;
long long cnt;
bool check[101][101], visit[101][101];
int dy[4] = { -1,1,0,0 }, dx[4] = { 0,0,1,-1 };
vector<long long> ans;

void getans(int y, int x) {

	//종료 조건
	if (check[y][x] == true || visit[y][x] == true) return;

	visit[y][x] = true;
	cnt++;

	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i]; int nx = x + dx[i];
		if (ny < 1 || ny > row || nx<1 || nx>col) continue;
		getans(ny, nx);
	}
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);


	string str;

	cin >> row;
	col = row;

	//check에 길 표시
	for (int i = 1; i <= row; i++) {
		cin >> str;
		for (int j = 1; j <= col; j++)
			if (str[j - 1] == '0') check[i][j] = true;
			else check[i][j] = false;
	}

	//지나갈 수 있는 면적 cnt로 체크 후 push
	//매타임 cnt 초기화
	for (int y = 1; y <= row; y++)
		for (int x = 1; x <= col; x++) {
			getans(y, x);
			if (cnt != 0)
				ans.push_back(cnt);
			cnt = 0;
		}

	cout << ans.size() << '\n';
	sort(ans.begin(), ans.end());
	for (int i = 0; i < ans.size(); i++) {
		if (ans[i] != 0)
			cout << ans[i] << '\n';
	}

	return 0;
}