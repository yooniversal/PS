#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#define MAX 100001
using namespace std;

bool chk[MAX];

bool cmp(vector<int>& a, vector<int>& b) {
    return a.size() < b.size();
}

vector<int> solution(string s) {
    vector<int> answer;

    vector<vector<int>> a;
    vector<int> b;
    int num = 0;
    for (int i = 1; i < s.size() - 1; i++) {
        if (s[i] == '}') {
            if (num) b.push_back(num);
            a.push_back(b); b.clear();
            num = 0;
            continue;
        }
        if (s[i] == '{') {
            continue;
        }
        if (s[i] == ',') {
            if (num) b.push_back(num);
            num = 0;
            continue;
        }
        num = num * 10 + (s[i] - '0');
    }
    sort(a.begin(), a.end(), cmp);

    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < a[i].size(); j++) {
            if (!chk[a[i][j]]) {
                answer.push_back(a[i][j]);
                chk[a[i][j]] = true;
            }
        }
    }

    return answer;
}