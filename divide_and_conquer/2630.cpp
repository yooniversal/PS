//2630

#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <deque>
#include <list>
#include <algorithm>
using namespace std;

int white, blue;

bool isWhite(int r_s, int r_e, int c_s, int c_e, int** arr) {
	for (int i = r_s; i <= r_e; i++)
		for (int j = c_s; j <= c_e; j++)
			if (arr[i][j] == 1)
				return false;
	return true;
}

bool isBlue(int r_s, int r_e, int c_s, int c_e, int** arr) {
	for (int i = r_s; i <= r_e; i++)
		for (int j = c_s; j <= c_e; j++)
			if (arr[i][j] == 0)
				return false;
	return true;
}

void dfs(int r_s, int r_e, int c_s, int c_e, int** arr) {
	
	//종료 조건
	if (isWhite(r_s, r_e, c_s, c_e, arr)) {
		white++;
		return;
	}
	else if (isBlue(r_s, r_e, c_s, c_e, arr)) {
		blue++;
		return;
	}
	int midr = (r_s + r_e) / 2;
	int midc = (c_s + c_e) / 2;

	//가로 세로를 절반으로 나눠 4분할이 이루어 지므로
	//dfs도 각 범위에 맞춰 절반씩 나눠준다
	//조건에 충족하는 케이스는 종료 조건에서 white or blue 카운팅하고 소멸
	dfs(r_s, midr, c_s, midc, arr);
	dfs(r_s, midr, midc + 1, c_e, arr);
	dfs(midr+1, r_e, midc+1, c_e, arr);
	dfs(midr + 1, r_e, c_s, midc, arr);
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;

	//2차원 배열 동적 할당
	int** arr = new int*[n];
	for (int i = 0; i < n; i++)
		arr[i] = new int[n];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> arr[i][j];

	dfs(0, n-1, 0, n-1, arr);

	for (int i = 0; i < n; i++)
		delete[] arr[i];
	delete[] arr;

	cout << white << "\n" << blue;

	return 0;
}