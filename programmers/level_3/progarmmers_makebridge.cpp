#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
const int MAX = 101;
const int INF = 987654321;

int uni[MAX];

int find(int a) {
    if (uni[a] == a) return a;
    return uni[a] = find(uni[a]);
}

void make_union(int a, int b) {
    int pa = find(a), pb = find(b);
    if (pa < pb) uni[b] = pa;
    else uni[a] = pb;
}

bool cmp(vector<int>& a, vector<int>& b) {
    return a[2] < b[2];
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;

    sort(costs.begin(), costs.end(), cmp);
    for (int i = 0; i < MAX; ++i) uni[i] = i;

    for (int i = 0; i < costs.size(); ++i) {
        for (int j = 0; j < 3; ++j)
            cout << costs[i][j] << " ";
        cout << '\n';
    }


    for (int i = 0; i < costs.size(); ++i) {
        int s = find(costs[i][0]), e = find(costs[i][1]);
        int c = costs[i][2];

        if (s != e) {
            make_union(s, e);
            answer += c;
        }
    }

    return answer;
}