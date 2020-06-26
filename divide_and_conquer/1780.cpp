//1780

#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <deque>
#include <list>
#include <algorithm>
using namespace std;

int minu, zero, one, n;

bool check(int x, int y, int** arr, int size) {
	int temp = arr[x][y];
	for (int i = x; i < x+size; i++)
		for (int j = y; j < y+size; j++)
			if (arr[i][j] != temp)
				return false;
	return true;
}

void dfs(int x, int y, int** arr, int size = n) {

	//���� ����
	//üũ�ϴ� �Լ��� 3������ �ð� �ʰ�������
	//�����ϸ� ���� �ʰ��ϱ�
	if (check(x, y, arr, size)) {
		if (arr[x][y] == 0) zero++;
		else if (arr[x][y] == 1) one++;
		else minu++;
		return;
	}
	//3*3�� ������ ��
	else if (size == 3) {
		for (int i = x; i < x + size; i++)
			for (int j = y; j < y + size; j++)
				if (arr[i][j] == -1) minu++;
				else if (arr[i][j] == 0) zero++;
				else one++;
		return;
	}
	else {
		dfs(x, y, arr, size / 3);
		dfs(x, y + size / 3, arr, size / 3);
		dfs(x, y + (size / 3) * 2, arr, size / 3);
		dfs(x + size / 3, y, arr, size / 3);
		dfs(x + size / 3, y + size / 3, arr , size / 3);
		dfs(x + size / 3, y + (size / 3) * 2, arr, size / 3);
		dfs(x + (size / 3) * 2, y, arr, size / 3);
		dfs(x + (size / 3) * 2, y + size / 3, arr, size / 3);
		dfs(x + (size / 3) * 2, y + (size / 3) * 2, arr, size / 3);
	}
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n;

	//2���� �迭 ���� �Ҵ�
	int** arr = new int* [n];
	for (int i = 0; i < n; i++)
		arr[i] = new int[n];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> arr[i][j];

	dfs(0, 0, arr);

	for (int i = 0; i < n; i++)
		delete[] arr[i];
	delete[] arr;

	cout << minu << "\n" << zero << "\n" << one;

	return 0;
}