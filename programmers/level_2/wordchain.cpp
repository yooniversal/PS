#include <string>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;

    map<string, bool> m;
    int turn = 1;
    char last = NULL;
    for (int i = 0; i < words.size(); i++) {
        if (m[words[i]] || (last != NULL && last != words[i][0])) {
            answer.push_back(turn);
            answer.push_back(i / n + 1);
            break;
        }
        m[words[i]] = true;
        if (turn != n) turn++;
        else turn = 1;
        last = words[i][words[i].size() - 1];
    }

    if (answer.empty()) {
        answer.push_back(0);
        answer.push_back(0);
    }

    return answer;
}