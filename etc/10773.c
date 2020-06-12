//10773

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS
#define min(a, b) (((a) > (b)) ? (b) : (a))

long long int arr[100001];

int main() {

	int k, point = 0;
	long long int temp, ans = 0;

	scanf("%d", &k);

	while (k--) {

		scanf("%lld", &temp);
		
		if (temp != 0) {
			arr[point] = temp;
			point++;
		}
		else {
			arr[--point] = 0;
		}
	}

	for (int i = 0; i < point; i++)
		ans += arr[i];

	printf("%lld", ans);

	return 0;
}