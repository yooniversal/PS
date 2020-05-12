//1546

#include <stdio.h>
#include <stdlib.h>

int main() {

	int T, i;
	double temp, max=0.0, result=0.0, keep;

	scanf("%d", &T);
	keep = (double)T;

	while (T != 0) {
		scanf("%lf", &temp);
		result += temp;
		if (max < temp) max = temp;

		T--;
	}
	
	result = result / max * 100.0;

	printf("%lf", result/keep);

	return 0;
}