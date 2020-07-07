//1316

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int continum(char* a, int num);
int main(void)
{
    char input[101], keep[101];
    int T, ans = 0, i, j, cnt=0;

    scanf("%d", &T);

    while (T != 0) {

        memset(keep, NULL, sizeof(char)*101);
        memset(input, NULL, sizeof(char)*101);
        
        scanf("%s", input);

        for(i = 0; i < strlen(input); i++) {
            keep[strlen(keep)] = input[i];
            // search saved char in keep
            for (j = 0; j < strlen(keep)-1; j++){
                if(i!=0)
                    if (keep[strlen(keep) - 2] != keep[strlen(keep) - 1]) {
                        if (keep[j] == keep[strlen(keep) - 1]) {
                            i = strlen(input);
                            break;
                        }
                    }
            }
            if (continum(input, i) != 1)
                i = continum(input, i);
            if(i == strlen(input)-1)
                ans++;
        }
        T--;
    }
    
    printf("%d", ans);

    return 0;
}

int continum(char* a, int num) {
    char temp = a[num];
    int i=1;

    while (a[num + i] == temp) {
        i++;
    }
    return (num+i-1);
}