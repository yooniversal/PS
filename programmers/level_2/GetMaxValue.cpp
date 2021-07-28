#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <algorithm>
#include <iostream>
#include <cstring>

using namespace std;

vector<int> num;
vector<char> oper;
bool chk[10001];

long long solve(string& op) {
    long long ret = 0;
    deque<long long> number, number_tmp;
    for (int i = 0; i < num.size(); i++) number.push_back(num[i]);

    for (int oidx = 0; oidx < 3; oidx++) {
        for (int i = 0; i < oper.size(); i++) {
            if (chk[i]) continue;
            //부호 차례가 맞다면
            if (op[oidx] == oper[i]) {
                chk[i] = true;
                long long a = 0, b = 0;
                a = number.front(); number.pop_front();
                b = number.front(); number.pop_front();
                if (op[oidx] == '+') a += b;
                else if (op[oidx] == '-') a -= b;
                else a *= b;
                number.push_front(a);
            }
            //부호 차례가 아니라면
            else {
                long long temp = number.front(); number.pop_front();
                number_tmp.push_back(temp);
            }
        }
        while (number.size()) {
            number_tmp.push_back(number.front());
            number.pop_front();
        }
        number.clear();
        number = number_tmp;
        number_tmp.clear();
    }

    return abs(number[0]);
}

long long solution(string expression) {
    long long answer = 0;

    long long a = 0;
    for (int i = 0; i < expression.size(); i++) {
        if ('0' <= expression[i] && expression[i] <= '9') {
            a = a * 10 + (expression[i] - '0');
        }
        else {
            num.push_back(a); a = 0;
            oper.push_back(expression[i]);
        }
    }
    num.push_back(a);

    vector<string> s;
    s.push_back("+-*");
    s.push_back("+*-");
    s.push_back("-+*");
    s.push_back("-*+");
    s.push_back("*+-");
    s.push_back("*-+");

    for (int i = 0; i < 6; i++) {
        memset(chk, false, sizeof(chk));
        answer = max(answer, solve(s[i]));
    }

    return answer;
}