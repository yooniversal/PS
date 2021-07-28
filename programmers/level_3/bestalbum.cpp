#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
using namespace std;

struct info {
    int g, p, n;
    bool operator<(info& i) {
        if (g != i.g) return g > i.g;
        return p > i.p;
    }
};

map<string, int> total;
vector<info> v;
int chk[101];

bool cmp(string& a, string& b) {
    return total[a] > total[b];
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;

    //장르별 play 합산
    for (int i = 0; i < genres.size(); ++i)
        total[genres[i]] += plays[i];

    vector<string> g = genres;
    sort(g.begin(), g.end());
    g.erase(unique(g.begin(), g.end()), g.end());
    sort(g.begin(), g.end(), cmp);

    int cnt = g.size();
    for (int i = 0; i < g.size(); ++i)
        total[g[i]] = cnt--;

    for (int i = 0; i < genres.size(); ++i)
        v.push_back({ total[genres[i]], plays[i], i });

    sort(v.begin(), v.end());

    for (int i = 0; i < v.size(); ++i) {
        if (chk[v[i].g] >= 2) continue;
        chk[v[i].g]++;
        answer.push_back(v[i].n);
    }

    return answer;
}