//9663

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int subtemp;

int hasnotzero(int arr[][9]) {
	int i, j;

	for (i = 0; i < 9; i++)
		for (j = 0; j < 9; j++)
			if (arr[i][j] == 0)
				return 0;
	return 1;
}
int isSameValue(int arr[][9]) {
	int i, j, row, col;

	for (row = 0; row < 9; row++)
		for (col = 0; col < 9; col++) {

			//row check
			for (i = 0; i < 9; i++)
				for (j = i + 1; j < 9; j++)
					if (arr[row][i] == arr[row][j])
						return 1;

			//col check
			for (i = 0; i < 9; i++)
				for (j = i + 1; j < 9; j++)
					if (arr[i][col] == arr[j][col])
						return 1;

			//box check
			if (row < 3 && col < 3) {
				for (i = 0; i < 3; i++)
					for (j = 0; j < 3; j++)
						if (arr[row][col] == arr[i][j])
							if (!(row == i && col == j))
								return 1;
			}
			else if (row < 3 && (col >= 3 && col < 6)) {
				for (i = 0; i < 3; i++)
					for (j = 3; j < 6; j++)
						if (arr[row][col] == arr[i][j])
							if (!(row == i && col == j))
								return 1;
			}
			else if (row < 3 && (col >= 6 && col < 9)) {
				for (i = 0; i < 3; i++)
					for (j = 6; j < 9; j++)
						if (arr[row][col] == arr[i][j])
							if (!(row == i && col == j))
								return 1;
			}
			else if ((row >= 3 && row < 6) && col < 3) {
				for (i = 3; i < 6; i++)
					for (j = 0; j < 3; j++)
						if (arr[row][col] == arr[i][j])
							if (!(row == i && col == j))
								return 1;
			}
			else if ((row >= 3 && row < 6) && (col >= 3 && col < 6)) {
				for (i = 3; i < 6; i++)
					for (j = 3; j < 6; j++)
						if (arr[row][col] == arr[i][j])
							if (!(row == i && col == j))
								return 1;
			}
			else if ((row >= 3 && row < 6) && (col >= 6 && col < 9)) {
				for (i = 3; i < 6; i++)
					for (j = 6; j < 9; j++)
						if (arr[row][col] == arr[i][j])
							if (!(row == i && col == j))
								return 1;
			}
			else if ((row >= 6 && row < 9) && col < 3) {
				for (i = 6; i < 9; i++)
					for (j = 0; j < 3; j++)
						if (arr[row][col] == arr[i][j])
							if (!(row == i && col == j))
								return 1;
			}
			else if ((row >= 6 && row < 9) && (col >= 3 && col < 6)) {
				for (i = 6; i < 9; i++)
					for (j = 3; j < 6; j++)
						if (arr[row][col] == arr[i][j])
							if (!(row == i && col == j))
								return 1;
			}
			else if ((row >= 6 && row < 9) && (col >= 6 && col < 9)) {
				for (i = 6; i < 9; i++)
					for (j = 6; j < 9; j++)
						if (arr[row][col] == arr[i][j])
							if (!(row == i && col == j))
								return 1;
			}
		}

	return 0;
}

void fill(int arr[][9], int row, int col) {

	int a, b;
	
	subtemp = row*9+col;

	if (subtemp < 81) {
		if (!isSameValue(arr)) {
			for (a = 0; a < 9; a++) {
				for (b = 0; b < 9; b++)
					printf("%d ", arr[a][b]);
				printf("\n");
			}
			printf("\n");
			return;
		}
		else {
			if (arr[row][col] == 0) {
				for (a = 1; a <= 9; a++) {
					arr[row][col] = a;
					subtemp++;
					fill(arr, subtemp/9, subtemp%9);
				}
			}
		}
	}

	
}

int main() {
	int i, j;

	int arr[9][9];

	for (i = 0; i < 9; i++)
		for (j = 0; j < 9; j++)
			scanf("%d", &arr[i][j]);

	fill(arr, 0, 0);

	return 0;
}