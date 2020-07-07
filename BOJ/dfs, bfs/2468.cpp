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

	//���� ����
	if (check[y][x] == 1 || chk[y][x] == 1) {
		return;
	}

	check[y][x] = 1;
	
	//��� Ž�� && ������ Ž��
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i]; int nx = x + dx[i];
		if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
		//���� ������, üũ���� �ʾҴٸ�
		if (chk[ny][nx] == 0 && check[ny][nx] == 0) {
			getans(ny, nx);
		}
	}
	
	//���� ĭ���� �̵��ؼ� ���������� ��ü Ž��
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i]; int nx = x + dx[i];
		if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
		getans(ny, nx);
	}
}

//��� ������ 1, ����� ������ 0
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

	//���̿� ���� �� ��ȯ
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