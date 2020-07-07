//14501

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max(a, b) (((a)>(b)) ? (a) : (b))

int T[17], P[17], n, ans = -1, subans = 0;

void dfs(int day) {
	
	//종료 조건
	if (day + T[day] > n + 1) {
		if (day < n)
			dfs(day + 1);
		ans = max(subans, ans);
		return;
	}

	subans += P[day];
	//printf("day:%d  %d += %d\n", day, subans-P[day], P[day]);

	dfs(day + T[day]);
	subans -= P[day];

	while (day < n) {
		dfs(day + 1);
		day++;
	}
}

int main(){

	scanf("%d", &n);

	for (int i = 1; i <= n; i++)
		scanf("%d %d", &T[i], &P[i]);

	T[n + 1] = 9999;

	//for(int i=1; i<=n; i++)
		dfs(1);

	printf("%d", ans);

	return 0;
}