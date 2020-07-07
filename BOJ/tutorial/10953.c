//10953

int main() {
	int a, b, T;

	scanf("%d", &T);

	while (T != 0) {
		scanf("%d,%d", &a, &b);

		printf("%d\n", a + b);
		T--;
	}

	return 0;
}