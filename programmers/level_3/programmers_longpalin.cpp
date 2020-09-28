#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int f(string& s, int idx) {
    int ret = 1;
    for (int i = 1; idx - i >= 0 && idx + i < s.size(); ++i) {
        if (s[idx - i] != s[idx + i]) break;
        ret += 2;
    }
    return ret;
}

int g(string& s, int idx, int idx2) {
    int ret = 2;
    for (int i = 1; idx - i >= 0 && idx2 + i < s.size(); ++i) {
        if (s[idx - i] != s[idx2 + i]) break;
        ret += 2;
    }
    return ret;
}

int solution(string s) {

    int ret = 0;
    for (int i = 0; i < s.size(); ++i) {
        ret = max(ret, f(s, i));
        printf("f(s, %d):%d\n", i, f(s, i));
    }

    for (int i = 0; i < s.size() - 1; ++i) {
        if (s[i] == s[i + 1]) ret = max(ret, g(s, i, i + 1));
    }

    return ret;
}