#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
using namespace std;

struct LR {
    int l, r;
    LR(int a, int b) : l(a), r(b) {}
    bool operator<(const LR& s) const {
        if (r - l != s.r - s.l) return r - l < s.r - s.l;
        return l < s.l;
    }
};

map<string, int> kind;
int chk[100001];
vector<int> ng; //new gems
vector<LR> v;

vector<int> solution(vector<string> gems) {
    vector<int> answer;
    ng.resize(gems.size());

    int kinds = 0;
    for (int i = 0; i < gems.size(); ++i) {
        if (kind[gems[i]]) {
            ng[i] = kind[gems[i]];
            continue;
        }
        kind[gems[i]] = ++kinds;
        ng[i] = kinds;
    }

    int cnt = 0, st = 0;
    for (int i = 0; i < ng.size(); ++i) {
        if (chk[ng[i]]++ == 0) ++cnt;
        while (cnt == kinds && st <= i) {
            v.push_back(LR(st, i));
            if (--chk[ng[st++]] == 0) {
                --cnt;
                break;
            }
        }
    }
    sort(v.begin(), v.end());
    answer.push_back(v[0].l + 1);
    answer.push_back(v[0].r + 1);

    return answer;
}