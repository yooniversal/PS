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
	
	//���� ����
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

	//���� ���θ� �������� ���� 4������ �̷�� ���Ƿ�
	//dfs�� �� ������ ���� ���ݾ� �����ش�
	//���ǿ� �����ϴ� ���̽��� ���� ���ǿ��� white or blue ī�����ϰ� �Ҹ�
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

	//2���� �迭 ���� �Ҵ�
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