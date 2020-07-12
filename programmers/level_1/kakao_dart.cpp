#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string dartResult) {
    int answer = 0, tmp = 0;
    vector<pair<int, char>> a;

    for (int i = 0; i < dartResult.size(); i++) {
        if ('0' <= dartResult[i] && dartResult[i] <= '9') {
            if (i > 0) {
                if ('0' <= dartResult[i - 1] && dartResult[i - 1] <= '9')
                    tmp = tmp * 10 + (dartResult[i] - '0');
                else {
                    a.push_back({ tmp, dartResult[i - 1] });
                    tmp = dartResult[i] - '0';
                }
            }
            else if (i == 0)  tmp = dartResult[i] - '0';
        }
        else if (dartResult[i] == 'S') tmp = tmp;
        else if (dartResult[i] == 'D') tmp = tmp * tmp;
        else if (dartResult[i] == 'T') tmp = tmp * tmp * tmp;

        if (i == dartResult.size() - 1)
            a.push_back({ tmp, dartResult[i] });
    }

    for (int i = 0; i < a.size(); i++) {
        if (a[i].second == '*') {
            if (i > 0) a[i - 1].first *= 2;
            a[i].first *= 2;
        }
        else if (a[i].second == '#') a[i].first *= -1;
    }

    for (int i = 0; i < a.size(); i++) answer += a[i].first;

    return answer;
}