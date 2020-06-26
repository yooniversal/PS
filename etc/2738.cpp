//2738

#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <vector>
#include <deque>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int row, col, tmp;
	int arr1[101][101], arr2[101][101];

	cin >> row >> col;
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			cin >> arr1[i][j];
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			cin >> tmp;
			arr2[i][j] = arr1[i][j] + tmp;
		}
	}


	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			cout << arr2[i][j] << " ";
		}
		cout << '\n';
	}



	return 0;
}