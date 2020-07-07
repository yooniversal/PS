//4344

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

	int T, num, i, aver, cnt;
	int score[1000];
	double ans;

	scanf("%d", &T);

	while (T != 0) {
		aver = 0;
		cnt = 0;
		scanf("%d", &num);

		for (i = 0; i < num; i++) {
			scanf("%d", &score[i]);
			aver += score[i];
		}
		
		aver /= num;
		
		for (i = 0; i < num; i++)
			if(score[i] > aver)
				cnt++;
		
		ans = (double)cnt / (double)num * 100.0;
		printf("%.3lf%%\n", ans);

		T--;
	}

	return 0;
}