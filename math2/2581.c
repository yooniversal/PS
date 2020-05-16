//2581

#include <stdio.h>

int isnumber(int num);
int main() {

	int temp[10000], M, N, i, sum=0, min, cnt=0;

	scanf("%d %d", &M, &N);

	for (i = M; i <= N; i++) {
		if (isnumber(i)) {
			sum += i;
			temp[cnt] = i;
			cnt++;
		}
	}

	min = temp[0];
	for (i = 0; i < cnt; i++)
		if (min > temp[i])
			min = temp[i];

	if (sum != 0) {
		printf("%d\n", sum);
		printf("%d", min);
	}
	else if (!sum)
		printf("-1");

	return 0;
}

int isnumber(int num) {
	int i, cnt = 0;

	for (i = 1; i <= num; i++)
		if ((num % i) == 0) cnt++;

	if (cnt == 2) return 1;
	else return 0;
}