#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>

using namespace std;

int solution(string str1, string str2) {
    int answer = 0;

    map<string, int> ms1, ms2;
    map<string, bool> chk;

    vector<string> vs1, vs2;
    for (int i = 0; i < str1.size() - 1; i++) {
        if ((('a' <= str1[i] && str1[i] <= 'z') && ('a' <= str1[i + 1] && str1[i + 1] <= 'z')) ||
            (('a' <= str1[i] && str1[i] <= 'z') && ('A' <= str1[i + 1] && str1[i + 1] <= 'Z')) ||
            (('A' <= str1[i] && str1[i] <= 'Z') && ('a' <= str1[i + 1] && str1[i + 1] <= 'z')) ||
            (('A' <= str1[i] && str1[i] <= 'Z') && ('A' <= str1[i + 1] && str1[i + 1] <= 'Z'))) {
            if ('A' <= str1[i] && str1[i] <= 'Z') str1[i] = str1[i] - 'A' + 'a';
            if ('A' <= str1[i + 1] && str1[i + 1] <= 'Z') str1[i + 1] = str1[i + 1] - 'A' + 'a';
            string S = ""; S += str1[i]; S += str1[i + 1];
            vs1.push_back(S);
        }
    }
    for (int i = 0; i < str2.size() - 1; i++) {
        if ((('a' <= str2[i] && str2[i] <= 'z') && ('a' <= str2[i + 1] && str2[i + 1] <= 'z')) ||
            (('a' <= str2[i] && str2[i] <= 'z') && ('A' <= str2[i + 1] && str2[i + 1] <= 'Z')) ||
            (('A' <= str2[i] && str2[i] <= 'Z') && ('a' <= str2[i + 1] && str2[i + 1] <= 'z')) ||
            (('A' <= str2[i] && str2[i] <= 'Z') && ('A' <= str2[i + 1] && str2[i + 1] <= 'Z'))) {
            if ('A' <= str2[i] && str2[i] <= 'Z') str2[i] = str2[i] - 'A' + 'a';
            if ('A' <= str2[i + 1] && str2[i + 1] <= 'Z') str2[i + 1] = str2[i + 1] - 'A' + 'a';
            string S = ""; S += str2[i]; S += str2[i + 1];
            vs2.push_back(S);
        }
    }

    int same = 0, all = 0;
    vector<string> sameword;
    for (int i = 0; i < vs1.size(); i++) {
        all++;
        ms1[vs1[i]]++;
    }
    for (int i = 0; i < vs2.size(); i++) {
        if (ms1[vs2[i]] && !chk[vs2[i]]) {
            sameword.push_back(vs2[i]);
            chk[vs2[i]] = true;
        }
        all++;
        ms2[vs2[i]]++;
    }

    for (int i = 0; i < sameword.size(); i++) {
        same += min(ms1[sameword[i]], ms2[sameword[i]]);
        all += max(ms1[sameword[i]], ms2[sameword[i]]) - (ms1[sameword[i]] + ms2[sameword[i]]);
    }

    if (all != 0) return answer = floor(same / (double)all * 65536);
    else return 65536;
}