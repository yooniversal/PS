//2160

#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <vector>
#include <deque>
#include <cmath>
#include <algorithm>
using namespace std;

int n, ans, sub;
int arr[101][101], chk[101][101], check[101][101];
int dy[4] = { -1,1,0,0 }, dx[4] = { 0,0,1,-1 };

void getans(int y, int x) {

	//종료 조건
	if (check[y][x] == 1 || chk[y][x] == 1) {
		return;
	}

	check[y][x] = 1;
	
	//사방 탐색 && 끝까지 탐색
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i]; int nx = x + dx[i];
		if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
		//물에 안잠기고, 체크되지 않았다면
		if (chk[ny][nx] == 0 && check[ny][nx] == 0) {
			getans(ny, nx);
		}
	}
	
	//다음 칸으로 이동해서 최종적으로 전체 탐색
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i]; int nx = x + dx[i];
		if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
		getans(ny, nx);
	}
}

//잠긴 영역은 1, 안잠긴 영역은 0
void makechk(int h) {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (h >= arr[i][j])
				chk[i][j] = 1;
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int maxx;

	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
			if (i == 0 && j == 0) maxx = arr[i][j];
			else
				if (maxx < arr[i][j]) maxx = arr[i][j];
		}

	//높이에 따라 값 반환
	for (int i = 0; i < maxx; i++) {
		makechk(i);

		for(int y=0; y<n; y++)
			for(int x=0;x<n;x++)
				if (check[y][x] == 0 && chk[y][x] == 0) {
					getans(y, x);
					sub++;
				}
		
		ans = max(ans, sub);
		sub = 0;
		memset(check, 0, sizeof(check));
	}

	cout << ans;

	return 0;
}