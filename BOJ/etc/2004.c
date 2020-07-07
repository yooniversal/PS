//2004

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS
#define min(a, b) (((a) > (b)) ? (b) : (a))

long long int twocnt(long long int n) {

	long long int cnt=0;

	for (long long int i = 2; n/i >= 1; i *= 2) {
		cnt += n / i;
	}
	
	return cnt;
}

long long int fivecnt(long long int n) {

	long long int cnt=0;

	for (long long int i = 5; n / i >= 1; i *= 5) {
		cnt += n / i;
	}

	return cnt;
}

long long int anscnt(long long int n, long long int r) {

	long long int sumfive, sumtwo;

	sumfive = fivecnt(n) - (fivecnt(n - r) + fivecnt(r));
	sumtwo = twocnt(n) - (twocnt(n - r) + twocnt(r));

	return min(sumfive, sumtwo);
}

int main() {

	long long int n, r;

	scanf("%lld %lld", &n, &r);

	printf("%lld", anscnt(n, r));

	return 0;
}