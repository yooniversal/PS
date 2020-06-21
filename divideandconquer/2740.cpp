//2740

#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

long long mat1[101][101], mat2[101][101];
int n, m, k;

long long matrix(int y, int x) {
	long long temp = 0;

	for (int i = 0; i < m; i++)
		temp += mat1[y][i] * mat2[i][x];

	return temp;
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> mat1[i][j];
	cin >> m >> k;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < k; j++)
			cin >> mat2[i][j];
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < k; j++)
			cout << matrix(i, j) << " ";
		cout << "\n";
	}

	return 0;
}