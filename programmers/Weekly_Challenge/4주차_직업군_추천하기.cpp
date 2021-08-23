#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> L;
vector<int> P;

pair<int, string> solve(const string& s) {
    pair<int, string> ret = { 0, "" };

    vector<string> LIST;
    string cur;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == ' ') {
            LIST.push_back(cur);
            cur = "";
        }
        else if (i == s.size() - 1) {
            cur += s[i];
            LIST.push_back(cur);
        }
        else
            cur += s[i];
    }

    ret.second = LIST[0];
    for (int i = 1; i < LIST.size(); ++i) {
        for (int j = 0; j < L.size(); ++j) {
            if (LIST[i] == L[j]) {
                ret.first += (6 - i) * P[j];
            }
        }
    }

    return ret;
}

string solution(vector<string> table, vector<string> languages, vector<int> preference) {
    P = preference;
    L = languages;

    int maxx = -1;
    string type;
    for (int i = 0; i < table.size(); ++i) {
        auto v = solve(table[i]);
        if (maxx < v.first || (maxx == v.first && v.second < type)) {
            maxx = v.first;
            type = v.second;
        }
    }

    return type;
}
