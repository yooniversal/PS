//2908

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(int* a, int* b);
int main(void)
{
    char a1[4], a2[4];
    int i, x, y;

    scanf("%s", a1);
    scanf("%s", a2);


    swap(&a1[0], &a1[2]);
    swap(&a2[0], &a2[2]);
    
    x=atoi(a1);
    y=atoi(a2);

    if (x >= y)
        printf("%d", x);
    else printf("%d", y);

    return 0;
}

void swap(char* a, char* b) {
    char temp;

    temp = *a;
    *a = *b;
    *b = temp;
}
