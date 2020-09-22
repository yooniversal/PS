#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
const int MAX = 10001;

struct L {
    int s, n;
    bool start;
    L(int a, int b, bool c) : s(a), n(b), start(c) {}
    bool operator<(const L& l) const {
        if (s == l.s) return start > l.start;
        return s < l.s;
    }
};

int uni[MAX];
bool chk[MAX];

int find(int a) {
    if (uni[a] == a) return a;
    return uni[a] = find(uni[a]);
}

void make_union(int a, int b) {
    int pa = find(a), pb = find(b);
    if (pa < pb) uni[b] = find(a);
    else uni[a] = find(b);
}

int solution(vector<vector<int>> routes) {
    int answer = 0;

    for (int i = 0; i < MAX; ++i) uni[i] = i;

    vector<L> dot;
    for (int i = 0; i < routes.size(); ++i) {
        dot.push_back(L(routes[i][0], i + 1, true));
        dot.push_back(L(routes[i][1], i + 1, false));
    }
    sort(dot.begin(), dot.end());

    int parent = -1;
    for (int i = 0; i < dot.size(); ++i) {
        if (dot[i].start) {
            if (parent != -1)
                make_union(find(parent), find(dot[i].n));
            else
                parent = dot[i].n;
        }
        else {
            if (chk[find(dot[i].n)]) continue;
            chk[find(dot[i].n)] = true;
            parent = -1;
            ++answer;
        }
    }

    return answer;
}