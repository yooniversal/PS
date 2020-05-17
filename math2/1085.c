//1085

#include <stdio.h>
#include <math.h>

int main() {

	int x, y, w, h, ans;

	scanf("%d %d %d %d", &x, &y, &w, &h);

	if (w / 2 < x)
		if (h / 2 < y)
			if (w - x > h - y)
				ans = h - y;
			else ans = w - x;
		else
			if (w - x > y)
				ans = y;
			else ans = w - x;
	else
		if (h / 2 < y)
			if (x > h - y)
				ans = h - y;
			else ans = x;
		else
			if (x > y)
				ans = y;
			else ans = x;

	printf("%d", ans);

	return 0;
}