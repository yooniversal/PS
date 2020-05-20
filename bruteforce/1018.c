//1018

#include <stdio.h>

int chardiff(char a[][8], char b[][50] ,int row, int col) {
	int i, j, cnt=0;

	for (i = row; i < row+8; i++)
		for (j = col; j < col+8; j++)
			if (a[i][j] != b[i][j])
				cnt++;

	return cnt;
}

int main() {

	int i, j, N, M, min_case1, min_case2;
	char value[50][50];
	char case1[8][8] = {
		{"WBWBWBWB"},
		{"BWBWBWBW"},
		{"WBWBWBWB"},
		{"BWBWBWBW"},
		{"WBWBWBWB"},
		{"BWBWBWBW"},
		{"WBWBWBWB"},
		{"BWBWBWBW"}
	};
	char case2[8][8] = {
		{"BWBWBWBW"},
		{"WBWBWBWB"},
		{"BWBWBWBW"},
		{"WBWBWBWB"},
		{"BWBWBWBW"},
		{"WBWBWBWB"},
		{"BWBWBWBW"},
		{"WBWBWBWB"}
	};
	
	scanf("%d %d", &N, &M);

	for(i=0; i<N; i++)
		scanf("%s", &value[i]);

	min_case1 = chardiff(case1, value, 0, 0);
	min_case2 = chardiff(case2, value, 0, 0);
	//printf("%d\n", min_case1);

	for (i = 0; i <= N - 8; i++)
		for (j = 0; j <= M - 8; j++)
			if (min_case1 > chardiff(case1, value, i, j))
				min_case1 = chardiff(case1, value, i, j);

	for (i = 0; i <= N - 8; i++)
		for (j = 0; j <= M - 8; j++)
			if (min_case2 > chardiff(case2, value, i, j)) {
				min_case2 = chardiff(case2, value, i, j);
				printf("%d\n", min_case2);
			}
	printf("%d %d\n", min_case1, min_case2);
	printf("%d\n", chardiff(case2, value, 0, 1));

	if (min_case1 < min_case2) printf("%d", min_case1);
	else printf("%d", min_case2);

	return 0;
}