#include <string>
#include <vector>
#include <iostream>
#define MAXSIZE 1001

using namespace std;

int min(int a, int b) {
    if (a < b) return a;
    else return b;
}

int solution(string s) {
    int answer = MAXSIZE;
    int len = s.size();

    //길이
    for (int i = 1; i <= len / 2 + 1; i++) {
        vector<string> cmp;
        string tmp;

        for (int j = 0; j < len; j++) {
            tmp += s[j];
            if (tmp.size() == i) {
                cmp.push_back(tmp);
                tmp = "";
            }
        }
        if (tmp.size()) cmp.push_back(tmp);

        string ans;
        int cnt = 1; tmp = cmp[0];
        for (int j = 1; j < cmp.size(); j++) {
            //일치
            if (tmp.compare(cmp[j]) == 0) cnt++;
            //불일치
            else {
                if (cnt != 1) ans += to_string(cnt);
                ans += tmp;

                cnt = 1;
                tmp = cmp[j];
            }
        }
        if (cnt != 1) ans += to_string(cnt);
        ans += tmp;

        answer = min(answer, ans.size());
    }

    return answer;
}
