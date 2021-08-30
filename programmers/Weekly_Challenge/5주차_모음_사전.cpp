#include <iostream>
#include <string>
#include <vector>

using namespace std;

const char kind[5] = { 'A', 'E', 'I', 'O', 'U' };

int get_kind(const char& c) {
    for (int i = 0; i < 5; ++i) {
        if (c == kind[i]) return i;
    }

    return -1;
}

string next_string(string s) {
    if (s.size() < 5) return s + 'A';

    int last = get_kind(s.back());
    if (last != 4) {
        s.pop_back();
        return s + kind[++last];
    }

    // 맨 뒤가 'U'면 반복
    while (s.back() == 'U') s.pop_back();
    last = get_kind(s.back());
    s.pop_back();

    return s + kind[++last];
}

int solve(const string& w) {
    int ret = 1;
    string cur = "A";

    while (cur != w) {
        ++ret;
        cur = next_string(cur);
    }

    return ret;
}

int solution(string word) {
    return solve(word);
}