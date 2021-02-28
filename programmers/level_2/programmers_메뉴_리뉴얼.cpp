#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int max_cnt[11];
bool cnt[21][27], chk[27], times[11];
string alpha;
vector<pair<int, string>> ret;

bool cmp(pair<int, string>& r1, pair<int, string>& r2) {
    if (r1.first != r2.first) return r1.first > r2.first;
    return r1.second < r2.second;
}

void DFS(vector<string>& orders, string cur, int prev, int sum, int person) {
    if (cur.size() >= 2 && times[cur.size()]) ret.push_back({ sum, cur });

    for (int i = prev + 1; i < alpha.size(); ++i) {
        int nextp = person, nsum = sum;
        for (int j = 0; j < orders.size(); ++j)
            if ((person & (1 << j)))
                if (!cnt[j][alpha[i] - 'A'])
                    nextp ^= (1 << j), --nsum;

        cur += alpha[i];
        if (nsum >= 2) DFS(orders, cur, i, nsum, nextp);
        cur.pop_back();
    }
}

vector<string> solution(vector<string> orders, vector<int> course) {
    for (int i = 0; i < course.size(); ++i)
        times[course[i]] = true;

    for (int i = 0; i < orders.size(); ++i) {
        for (int j = 0; j < orders[i].size(); ++j) {
            cnt[i][orders[i][j] - 'A'] = true;

            if (chk[orders[i][j] - 'A']) continue;
            chk[orders[i][j] - 'A'] = true;
            alpha += orders[i][j];
        }
    }
    sort(alpha.begin(), alpha.end());

    for (int i = 0; i < alpha.size(); ++i) {
        int sum = 0, person = 0;
        for (int j = 0; j < orders.size(); ++j)
            if (cnt[j][alpha[i] - 'A']) {
                ++sum;
                person |= (1 << j);
            }
        string cur = "";
        cur += alpha[i];
        DFS(orders, cur, i, sum, person);
    }

    vector<string> answer;
    sort(ret.begin(), ret.end(), cmp);
    for (int i = 0; i < ret.size(); ++i) {
        if (max_cnt[ret[i].second.size()] <= ret[i].first) {
            max_cnt[ret[i].second.size()] = ret[i].first;
            answer.push_back(ret[i].second);
        }
    }
    sort(answer.begin(), answer.end());

    return answer;
}