#include <string>
#include <vector>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;

vector<int> p[3][2][2][2];
vector<vector<int>> Q;
int len[4] = { 3, 2, 2, 2 };

int solve(int q, int pos, int a, int b, int c, int d, int score) {
    if (pos == 4) {
        int idx = lower_bound(p[a][b][c][d].begin(), p[a][b][c][d].end(), score) - p[a][b][c][d].begin();
        return p[a][b][c][d].size() - idx;
    }

    int ret = 0;
    if (Q[q][pos] == len[pos]) {
        for (int i = 0; i < len[pos]; ++i) {
            if (pos == 0) a = i;
            else if (pos == 1) b = i;
            else if (pos == 2) c = i;
            else d = i;

            ret += solve(q, pos + 1, a, b, c, d, score);
        }
    }
    else {
        if (pos == 0) a = Q[q][pos];
        else if (pos == 1) b = Q[q][pos];
        else if (pos == 2) c = Q[q][pos];
        else d = Q[q][pos];

        ret += solve(q, pos + 1, a, b, c, d, score);
    }
    return ret;
}

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;

    for (int i = 0; i < info.size(); ++i) {
        string tmp = "";
        int a = 0, b = 0, c = 0, d = -1;
        for (int j = 0; j < info[i].size(); ++j) {
            if (info[i][j] == ' ') {
                if (tmp == "cpp") a = 0;
                if (tmp == "java") a = 1;
                if (tmp == "python") a = 2;
                if (tmp == "backend") b = 0;
                if (tmp == "frontend") b = 1;
                if (tmp == "junior") c = 0;
                if (tmp == "senior") c = 1;
                if (tmp == "chicken") d = 0;
                if (tmp == "pizza") d = 1;

                if (d != -1) {
                    p[a][b][c][d].push_back(stoi(info[i].substr(j + 1)));
                    tmp = "";
                    break;
                }

                tmp = "";
                continue;
            }

            tmp += info[i][j];
        }
    }

    for (int a = 0; a < 3; ++a)
        for (int b = 0; b < 2; ++b)
            for (int c = 0; c < 2; ++c)
                for (int d = 0; d < 2; ++d)
                    sort(p[a][b][c][d].begin(), p[a][b][c][d].end());

    for (int i = 0; i < query.size(); ++i) {
        string tmp = "";
        vector<int> q(5, -1);
        int cur = 0;
        for (int j = 0; j < query[i].size(); ++j) {
            if (query[i][j] == ' ') {
                if (tmp == "cpp") q[0] = 0;
                if (tmp == "java") q[0] = 1;
                if (tmp == "python") q[0] = 2;
                if (tmp == "backend") q[1] = 0;
                if (tmp == "frontend") q[1] = 1;
                if (tmp == "junior") q[2] = 0;
                if (tmp == "senior") q[2] = 1;
                if (tmp == "chicken") q[3] = 0;
                if (tmp == "pizza") q[3] = 1;
                if (tmp == "-") q[cur] = cur == 0 ? 3 : 2;
                ++cur;

                if (cur == 4) {
                    q[4] = stoi(query[i].substr(j + 1));
                    Q.push_back(q);
                    break;
                }

                tmp = "";
                j += 4;
                continue;
            }
            tmp += query[i][j];
        }
    }

    for (int i = 0; i < query.size(); ++i)
        answer.push_back(solve(i, 0, -1, -1, -1, -1, Q[i][4]));

    return answer;
}