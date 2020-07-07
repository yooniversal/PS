#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string s) {
    int answer = 0;
    int pm;

    if (s[0] == '-') {
        pm = -1;
        s.erase(0, 1);
    }
    else if (s[0] == '+') {
        pm = 1;
        s.erase(0, 1);
    }
    else pm = 1;

    for (int i = 0; i < s.size(); i++) {
        answer = answer * 10 + (s[i] - '0');
        //cout << "answer:"<<answer<<endl;
    }


    answer *= pm;

    return answer;
}