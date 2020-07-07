#include <string>
#include <iostream>
using namespace std;

bool solution(string s)
{
    bool answer = true;

    int c1 = 0, c2 = 0;

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'p' || s[i] == 'P') c1++;
        if (s[i] == 'y' || s[i] == 'Y') c2++;
    }

    if (c1 == c2) answer = true;
    else answer = false;

    return answer;
}