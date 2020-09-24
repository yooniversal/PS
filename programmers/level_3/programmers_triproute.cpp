#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <iostream>
using namespace std;
const int MAX = 10001;

vector<int> node[MAX];
bool chk[MAX][MAX];
vector<vector<int>> ret;
int n, s;

void dfs(int cur, int cnt, vector<int>& route) {
    if (cnt == n) {
        ret.push_back(route);
        return;
    }

    for (int i = 0; i < node[cur].size(); ++i) {
        if (chk[cur][i]) continue;
        chk[cur][i] = true;
        int next = node[cur][i];
        route.push_back(next);
        dfs(next, cnt + 1, route);
        route.pop_back();
        chk[cur][i] = false;
    }
}

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;

    n = tickets.size();
    vector<string> cities;
    for (int i = 0; i < tickets.size(); ++i) {
        cities.push_back(tickets[i][0]);
        cities.push_back(tickets[i][1]);
    }
    sort(cities.begin(), cities.end());
    cities.erase(unique(cities.begin(), cities.end()), cities.end());

    map<string, int> toi;
    map<int, string> tos;
    for (int i = 0; i < cities.size(); ++i) {
        toi[cities[i]] = i;
        tos[i] = cities[i];
    }

    vector<vector<int>> v;
    for (int i = 0; i < tickets.size(); ++i) {
        vector<int> c(2);
        c = { toi[tickets[i][0]], toi[tickets[i][1]] };
        node[c[0]].push_back(c[1]);
        v.push_back(c);
    }

    s = toi["ICN"];
    vector<int> R;
    dfs(s, 0, R);

    sort(ret.begin(), ret.end());

    answer.push_back("ICN");
    for (int i = 0; i < ret[0].size(); ++i)
        answer.push_back(tos[ret[0][i]]);

    return answer;
}