//1152

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char* input = malloc(sizeof(char) * 1000001);
    int i, cnt=0;

    gets(input);

    char* token = strtok(input, " ");

    while (token != NULL) {
        //printf("%s\n", token);
        token = strtok(NULL, " ");
        cnt++;
    }

    printf("%d", cnt);

    return 0;
}
