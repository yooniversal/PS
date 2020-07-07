//1065

#include <stdio.h>
#include <stdlib.h>

int first(int* a);
void keep(int* a, int n);
int main() {
	int i, n, arr[4] = { 0 }, d, cnt, ans = 0, temp, realnum;

	scanf("%d", &n);

	while (n != 0) {

		keep(arr, n);
		temp = first(arr);
		realnum = 4 - temp;

		d = arr[2] - arr[3];

		cnt = 0;

		for (i = temp; i < 3; i++) {
			if (d == arr[i] - arr[i + 1])
				cnt++;
			if (cnt == realnum-1)
				ans++;
		}

		if (temp == 3)
			ans++;

		n--;
	}
	printf("%d", ans);

	return 0;
}

void keep(int* a, int n) {
	int i;

	for (i = 3; i >= 0; i--) {
		a[i] = n % 10;
		n /= 10;
	}
}

int first(int* a) {
	int i, cnt=0;

	for (i = 0; i < 4; i++)
		if (a[i] != 0)
			return i;
}