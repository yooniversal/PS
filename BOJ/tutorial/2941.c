//2941

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char input[101];
    int ans = 0, i;

    scanf("%s", input);

    for (i = 0; i < strlen(input); i++) {
        switch (input[i]) {
        case 'a':
            ans++;
            break;
        case 'b':
            ans++;
            break;
        case 'c':
            if (input[i + 1] == '=') {
                i++;
                ans++;
                break;
            }
            else if (input[i + 1] == '-') {
                i++;
                ans++;
                break;
            }
            else {
                ans++;
                break;
            }
        case 'd':
            if (input[i + 1] == 'z') {
                if (input[i + 2] == '=') {
                    i += 2;
                    ans++;
                    break;
                }
                else {
                    i++;
                    ans += 2;
                    break;
                }
            }
            else if (input[i + 1] == '-') {
                i++;
                ans++;
                break;
            }
            else {
                ans++;
                break;
            }
        case 'e':
            ans++;
            break;
        case 'f':
            ans++;
            break;
        case 'g':
            ans++;
            break;
        case 'h':
            ans++;
            break;
        case 'i':
            ans++;
            break;
        case 'j':
            ans++;
            break;
        case 'k':
            ans++;
            break;
        case 'l':
            if (input[i + 1] == 'j') {
                i++;
                ans++;
                break;
            }
            else {
                ans++;
                break;
            }
        case 'm':
            ans++;
            break;
        case 'n':
            if (input[i + 1] == 'j') {
                i++;
                ans++;
                break;
            }
            else {
                ans++;
                break;
            }
        case 'o':
            ans++;
            break;
        case 'p':
            ans++;
            break;
        case 'q':
            ans++;
            break;
        case 'r':
            ans++;
            break;
        case 's':
            if (input[i + 1] == '=') {
                i++;
                ans++;
                break;
            }
            else {
                ans++;
                break;
            }
        case 't':
            ans++;
            break;
        case 'u':
            ans++;
            break;
        case 'v':
            ans++;
            break;
        case 'w':
            ans++;
            break;
        case 'x':
            ans++;
            break;
        case 'y':
            ans++;
            break;
        case 'z':
            if (input[i + 1] == '=') {
                i++;
                ans++;
                break;
            }
            else {
                ans++;
                break;
            }
        default:
            break;
        }
    }

    printf("%d", ans);

    return 0;
}

