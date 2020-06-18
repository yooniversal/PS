//1002

#include <stdio.h>
#include <math.h>

double diff(double x, double y) {
	if (x > y) return x-y;
	else return y-x;
}

int main() {

	int T;
	double diag, x1, x2, y1, y2, r1, r2, n1, n2;

	scanf("%d", &T);

	while (T != 0) {
		scanf("%lf %lf %lf %lf %lf %lf", &x1, &y1, &r1, &x2, &y2, &r2);

		if ((x1 - x2) > 0) n1 = x1 - x2;
		else n1 = x2 - x1;

		if ((y1 - y2) > 0) n2 = y1 - y2;
		else n2 = y2 - y1;

		diag = n1 * n1 + n2 * n2;

		//printf("%lf %lf %lf\n", diag, r1 + r2, diff(r1,r2));
		
		if (n1 == 0 && n2 == 0) {
			if (r1 == r2) printf("-1\n");
			else printf("0\n");
		}
		else {
			if (((r1 + r2)*(r1 + r2) < diag) || (diag < diff(r1, r2)* diff(r1, r2))) printf("0\n");
			else if (((r1 + r2)* (r1 + r2) == diag) || (diff(r1, r2)* diff(r1, r2) == diag)) printf("1\n");
			else printf("2\n");
		}
		
		T--;
	}
}