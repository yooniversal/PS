//1011

#include <stdio.h>

unsigned int calcul(int step) {
	int s;
	unsigned int result;

	s = step / 2;

	//step is odd
	if (step % 2)
		result = s * (s + 1) + s + 1;
	else
		result = s * (s + 1);

	return result;
}

int main() {

	int T;
	int cnt = 1;
	unsigned int start, end, dist;

	scanf("%d", &T);

	while (T != 0) {
		cnt = 1;
		scanf("%d %d", &start, &end);

		dist = end - start;

		if (dist <= 2) printf("%d\n", dist);
		else {
			while (calcul(cnt) < dist) {
				cnt++;
			}
			printf("%d\n", cnt);
		}
		T--;
	}
}