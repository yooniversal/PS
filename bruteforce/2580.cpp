//2580

#include <iostream>
using namespace std;

int arr[9][9];
bool row[9][9];
bool col[9][9];
bool squ[9][9];

void printa() {

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++)
			printf("%d ", arr[i][j]);
		printf("\n");
	}
}

void sudoku(int cnt) {

    int x = cnt / 9;
    int y = cnt % 9;

    if (cnt == 81)
    {
        printa();
        exit(0);
    }

    if (arr[x][y] == 0) {
        for (int i = 1; i <= 9; i++) {
            if (row[x][i] == false && col[y][i] == false && squ[(x / 3) * 3 + (y / 3)][i] == false) {
                row[x][i] = true;
                col[y][i] = true;
                squ[(x / 3) * 3 + (y / 3)][i] = true;
                arr[x][y] = i;
                sudoku(cnt + 1);
                arr[x][y] = 0;
                row[x][i] = false;
                col[y][i] = false;
                squ[(x / 3) * 3 + (y / 3)][i] = false;
            }
        }
    }
    else
        sudoku(cnt + 1);
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//input
	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++) {
			cin >> arr[i][j];
            if (arr[i][j] != 0) {
                row[i][arr[i][j]] = true;
                col[j][arr[i][j]] = true;
                squ[(i / 3) * 3 + (j / 3)][arr[i][j]] = true;
            }
		}

	sudoku(0);

	return 0;

}
