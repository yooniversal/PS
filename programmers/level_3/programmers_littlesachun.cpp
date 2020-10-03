#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
struct info {
    pair<int, int> s, e;
    info() : s({ -1, -1 }), e({ -1, -1 }) {}
};

info alpha[30];
char b[110][110];
bool c[30];

bool f(const info& cur) {
    pair<int, int> s = cur.s, s2 = cur.s, e = cur.e;
    int dx = 0, dy = 0;
    if (s.first > e.first) dx = -1;
    else if (s.first < e.first) dx = 1;

    if (s.second > e.second) dy = -1;
    else if (s.second < e.second) dy = 1;

    bool flag = true;
    // x -> y
    while (dx != 0 && s2.first != e.first) {
        s2.first += dx;
        if (s2.first == e.first && s2.second == e.second) return true;
        if (b[s2.first][s2.second] != '.') { flag = false; break; }
    }
    while (flag && dy != 0 && s2.second != e.second) {
        s2.second += dy;
        if (s2.first == e.first && s2.second == e.second) return true;
        if (b[s2.first][s2.second] != '.') { flag = false; break; }
    }

    // y -> x
    if (!flag) {
        while (dy != 0 && s.second != e.second) {
            s.second += dy;
            if (s.first == e.first && s.second == e.second) return true;
            if (b[s.first][s.second] != '.') return false;
        }
        while (dx != 0 && s.first != e.first) {
            s.first += dx;
            if (s.first == e.first && s.second == e.second) return true;
            if (b[s.first][s.second] != '.') return false;
        }
    }
    return false;
}

string solution(int m, int n, vector<string> board) {
    string answer = "";
    memset(c, false, sizeof(c));
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
            b[i][j] = board[i][j];

    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j) {
            if (board[i][j] == '.' || board[i][j] == '*') continue;
            if (!c[board[i][j] - 'A']) {
                alpha[board[i][j] - 'A'].s = { i, j };
                c[board[i][j] - 'A'] = true;
            }
            else {
                alpha[board[i][j] - 'A'].e = { i, j };
            }
        }

    vector<int> a;
    for (int i = 0; i < 30; ++i)
        if (c[i]) a.push_back(i);

    memset(c, false, sizeof(c));
    while (true) {
        int cnt = 0;
        vector<int> tmp;
        for (int i = 0; i < a.size(); ++i) {
            if (c[a[i]]) continue;
            if (f(alpha[a[i]])) {
                info A = alpha[a[i]];
                b[A.s.first][A.s.second] = '.';
                b[A.e.first][A.e.second] = '.';
                c[a[i]] = true;
                answer += a[i] + 'A';
                ++cnt;
                break;
            }
        }
        if (!cnt) break;
    }
    if (answer.size() != a.size()) return "IMPOSSIBLE";
    return answer;
}