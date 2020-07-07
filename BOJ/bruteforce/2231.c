//2231

#include <stdio.h>

int count(int n) {
	int cnt = 0;

	while (n != 0) {
		n /= 10;
		cnt++;
	}

	return cnt;
}

int subsum(int n) {
	int sum = 0;

	while (n != 0) {
		sum += n % 10;
		n = n / 10;
	}

	return sum;
}

int ans(int N) {
	int number;

	if (count(N) != 1) {
		for (number = (count(N) - 2) * 10; number <= N; number++) {
			if (subsum(number) + number == N) {
				return number;
			}
		}
		return 0;
	}
	else {
		for (number = 0; number <= N; number++) {
			if (subsum(number) + number == N) {
				return number;
			}
			return 0;
		}
		return 0;
	}

}

int main() {

	int N;

	scanf("%d", &N);

	printf("%d", ans(N));

	return 0;
}