#include <string>
#include <set>
#include <vector>
#include <iostream>
using namespace std;

set<int> s;

vector<int> solution(vector<string> operations) {
    vector<int> answer;

    for (int i = 0; i < operations.size(); ++i) {
        if (operations[i][0] == 'I') {
            int n = 0;
            if (operations[i][2] != '-') {
                for (int j = 2; j < operations[i].size(); ++j)
                    n = n * 10 + (operations[i][j] - '0');
                s.insert(n);
            }
            else {
                for (int j = 3; j < operations[i].size(); ++j)
                    n = n * 10 + (operations[i][j] - '0');
                s.insert(n * (-1));
            }
        }
        else {
            if (s.empty()) continue;
            if (operations[i][2] == '1') {
                set<int>::iterator it = s.end();
                s.erase(--it);
            }
            else {
                set<int>::iterator it = s.begin();
                s.erase(it);
            }
        }
    }

    if (!s.empty()) {
        set<int>::iterator maxx = s.end();
        set<int>::iterator minn = s.begin();
        --maxx;
        answer.push_back(*maxx);
        answer.push_back(*minn);
    }
    else {
        answer.push_back(0);
        answer.push_back(0);
    }

    return answer;
}