//9663
//non-completed

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
					if (arr[row][i] != 0)
					if (arr[row][i] == arr[row][j])
							return 1;

			//col check
			for (i = 0; i < 9; i++)
				for (j = i + 1; j < 9; j++)
					if (arr[i][col] != 0)
					if (arr[i][col] == arr[j][col])
						return 1;

			//box check
			if (row < 3 && col < 3) {
				for (i = 0; i < 3; i++)
					for (j = 0; j < 3; j++)
						if (arr[row][col] == arr[i][j])
							if (arr[i][j] != 0)
							if (!(row == i && col == j))
								return 1;
			}
			else if (row < 3 && (col >= 3 && col < 6)) {
				for (i = 0; i < 3; i++)
					for (j = 3; j < 6; j++)
						if (arr[row][col] == arr[i][j])
							if (arr[i][j] != 0)
							if (!(row == i && col == j))
								return 1;
			}
			else if (row < 3 && (col >= 6 && col < 9)) {
				for (i = 0; i < 3; i++)
					for (j = 6; j < 9; j++)
						if (arr[row][col] == arr[i][j])
							if (arr[i][j] != 0)
							if (!(row == i && col == j))
								return 1;
			}
			else if ((row >= 3 && row < 6) && col < 3) {
				for (i = 3; i < 6; i++)
					for (j = 0; j < 3; j++)
						if (arr[row][col] == arr[i][j])
							if (arr[i][j] != 0)
							if (!(row == i && col == j))
								return 1;
			}
			else if ((row >= 3 && row < 6) && (col >= 3 && col < 6)) {
				for (i = 3; i < 6; i++)
					for (j = 3; j < 6; j++)
						if (arr[row][col] == arr[i][j])
							if (arr[i][j] != 0)
							if (!(row == i && col == j))
								return 1;
			}
			else if ((row >= 3 && row < 6) && (col >= 6 && col < 9)) {
				for (i = 3; i < 6; i++)
					for (j = 6; j < 9; j++)
						if (arr[row][col] == arr[i][j])
							if (arr[i][j] != 0)
							if (!(row == i && col == j))
								return 1;
			}
			else if ((row >= 6 && row < 9) && col < 3) {
				for (i = 6; i < 9; i++)
					for (j = 0; j < 3; j++)
						if (arr[row][col] == arr[i][j])
							if (arr[i][j] != 0)
							if (!(row == i && col == j))
								return 1;
			}
			else if ((row >= 6 && row < 9) && (col >= 3 && col < 6)) {
				for (i = 6; i < 9; i++)
					for (j = 3; j < 6; j++)
						if (arr[row][col] == arr[i][j])
							if (arr[i][j] != 0)
							if (!(row == i && col == j))
								return 1;
			}
			else if ((row >= 6 && row < 9) && (col >= 6 && col < 9)) {
				for (i = 6; i < 9; i++)
					for (j = 6; j < 9; j++)
						if (arr[row][col] == arr[i][j])
							if (arr[i][j] != 0)
							if (!(row == i && col == j))
								return 1;			
			}
		}

	//if (!hasnotzero(arr))
	//	return 1;

	return 0;
}

void fill(int arr[][9], int row, int col) {

	int a, b, temp;
	
	subtemp = row*9+col;

	if (subtemp < 81) {
		if (hasnotzero(arr)) {
			if (isSameValue(arr)) {
				for (a = 0; a < 9; a++) {
					for (b = 0; b < 9; b++)
						printf("%d ", arr[a][b]);
					printf("\n");
				}
				exit(1);
			}
		}
		else {
			a = 1;
			while(1){
				//if(a==1)
				//	temp = arr[row][col];
				if (arr[row][col] == a - 1)
					arr[row][col] = a;
				//pruning
				if (isSameValue(arr))
					break;
				
				//112345 이런 경우 다음으로 넘어가기 [pruning]
				//if (!(row == 0 && col == 0))
				//	if (arr[(subtemp - 1) / 9][(subtemp - 1) % 9] == arr[row][col])
				//		break;

				subtemp++;
				fill(arr, subtemp / 9, subtemp % 9);

				if (a < 9)
					a++;
				else
					a = 1;
			}
			//if (isSameValue(arr))
			//	arr[row][col] = temp;

			//test print
			for (a = 0; a < 9; a++) {
				for (b = 0; b < 9; b++)
					printf("%d ", arr[a][b]);
				printf("\n");
			}
			printf("\n");
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
	//printf("%d", isSameValue(arr));

	return 0;
}