#include<string>
#include <iostream>

using namespace std;

bool solution(string s)
{
    bool answer = true;

    int test = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(') test++;
        else test--;

        if (test < 0) return false;
    }

    if (test == 0) return true;
    else return false;
}