//10809

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	char input[101];
	int i, ans[26];

	for (i = 0; i < 26; i++)
		ans[i] = -1;

	scanf("%s", &input);

	for (i = 0; i < strlen(input); i++) {
		if(ans[input[i] - 'a'] == -1)
			ans[input[i] - 'a'] = i;
	}

	for(i=0; i<26; i++)
		printf("%d ", ans[i]);

	return 0;
}