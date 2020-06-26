//1992

#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <deque>
#include <list>
#include <algorithm>
using namespace std;

bool isZero(int r_s, int r_e, int c_s, int c_e, int** arr) {
	for (int i = r_s; i <= r_e; i++)
		for (int j = c_s; j <= c_e; j++)
			if (arr[i][j] == 1)
				return false;
	return true;
}

bool isOne(int r_s, int r_e, int c_s, int c_e, int** arr) {
	for (int i = r_s; i <= r_e; i++)
		for (int j = c_s; j <= c_e; j++)
			if (arr[i][j] == 0)
				return false;
	return true;
}

void dfs(int r_s, int r_e, int c_s, int c_e, int** arr) {

	//종료 조건
	if (isZero(r_s, r_e, c_s, c_e, arr)) {
		cout << "0";
		return;
	}
	else if (isOne(r_s, r_e, c_s, c_e, arr)) {
		cout << "1";
		return;
	}
	//2*2만 남았을 때
	else if (r_e - r_s == 1 && c_e - c_s == 1) {
		cout << "(" << arr[r_s][c_s] << arr[r_s][c_e] << arr[r_e][c_s] << arr[r_e][c_e] << ")";
		return;
	}

	cout << "(";
	int midr = (r_s + r_e) / 2;
	int midc = (c_s + c_e) / 2;

	//가로 세로를 절반으로 나눠 4분할이 이루어 지므로
	//dfs도 각 범위에 맞춰 절반씩 나눠준다
	dfs(r_s, midr, c_s, midc, arr);
	dfs(r_s, midr, midc + 1, c_e, arr);
	dfs(midr + 1, r_e, c_s, midc, arr);
	dfs(midr + 1, r_e, midc + 1, c_e, arr);
	cout << ")";
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	string str;
	cin >> n;

	//2차원 배열 동적 할당
	int** arr = new int* [n];
	for (int i = 0; i < n; i++)
		arr[i] = new int[n];

	for (int i = 0; i < n; i++) {
		cin >> str;
		for (int j = 0; j < n; j++)
			if (str[j] == '0') arr[i][j] = 0;
			else arr[i][j] = 1;
	}

	dfs(0, n - 1, 0, n - 1, arr);

	for (int i = 0; i < n; i++)
		delete[] arr[i];
	delete[] arr;

	return 0;
}