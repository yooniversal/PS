//5622

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{   
    char input[16];
    int ans=0, i;

    scanf("%s", input);

    for(i=0; i<15; i++){
        switch (input[i]) {
        case 'A':
        case 'B':
        case 'C':
            ans += 3;
            break;
        case 'D':
        case 'E':
        case 'F':
            ans += 4;
            break;
        case 'G':
        case 'H':
        case 'I':
            ans += 5;
            break;
        case 'J':
        case 'K':
        case 'L':
            ans += 6;
            break;
        case 'M':
        case 'N':
        case 'O':
            ans += 7;
            break;
        case 'P':
        case 'Q':
        case 'R':
        case 'S':
            ans += 8;
            break;
        case 'T':
        case 'U':
        case 'V':
            ans += 9;
            break;
        case 'W':
        case 'X':
        case 'Y':
        case 'Z':
            ans += 10;
            break;
        default:
            break;
        }
    }

    printf("%d", ans);

    return 0;
}