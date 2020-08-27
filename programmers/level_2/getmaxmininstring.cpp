#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

string solution(string s) {
    string answer = "";

    vector<int> v;
    int num = 0;
    bool op = false;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == ' ') {
            if (op) {
                num *= -1;
                op = false;
            }
            v.push_back(num);
            num = 0;
        }
        else if (s[i] == '-') op = true;
        else {
            if (num == 0) num = s[i] - '0';
            else num = num * 10 + (s[i] - '0');
        }
    }
    if (op) num *= -1;
    v.push_back(num);
    sort(v.begin(), v.end());

    for (int i = 0; i < v.size(); i++)
        cout << v[i] << " ";

    if (v.size() == 1) {
        answer += to_string(v[0]) + ' ' + to_string(v[0]);
    }
    else {
        answer += to_string(v[0]) + ' ' + to_string(v[v.size() - 1]);
    }

    return answer;
}