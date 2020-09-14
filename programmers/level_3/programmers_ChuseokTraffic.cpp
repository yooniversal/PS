#include <string>
#include <vector>
#include <iostream>
using namespace std;

struct TIME {
    int s, e;
    TIME(int s, int e) : s(s), e(e) {}
};

int getTime(string& s) {
    int ret = 0;
    int h = (s[11] - '0') * 10 + (s[12] - '0');
    int m = (s[14] - '0') * 10 + (s[15] - '0');
    int sec = (s[17] - '0') * 10 + (s[18] - '0');
    ret = h * 3600 + m * 60 + sec; ret *= 1000;
    int ms = (s[20] - '0') * 100 + (s[21] - '0') * 10 + (s[22] - '0');
    ret += ms;
    return ret;
}

int runningTime(string s) {
    int sec = 0, ms = 0;
    bool dot = false;
    for (int i = 0; i < s.size(); i++) {
        if (!dot) {
            if (s[i] == 's') continue;
            if (s[i] != '.') sec = sec * 10 + s[i] - '0';
            else dot = true;
        }
        else
            if (s[i] != 's') ms = ms * 10 + s[i] - '0';
            else continue;
    }
    return sec * 1000 + ms;
}

int solution(vector<string> lines) {
    int answer = 0;

    vector<TIME> t; //start, end
    for (int i = 0; i < lines.size(); i++) {
        int e = getTime(lines[i]);
        int run = runningTime(lines[i].substr(24));
        if (e - run + 1 >= 0) t.push_back(TIME(e - run + 1, e));
        else t.push_back(TIME(0, e));
    }

    for (int i = 0; i < t.size(); i++) {
        int start = t[i].e;
        int tmp = 0;
        for (int j = i; j < t.size(); j++) {
            if (!(t[j].e < start || start + 999 < t[j].s))
                tmp++;
        }
        answer = max(answer, tmp);
    }

    return answer;
}