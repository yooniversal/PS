#include <string>
#include <queue>
#include <vector>
#include <cstring>
#include <iostream>
#define MAX 31

using namespace std;

int h, w;

bool solve(vector<string>& board) {
    bool ret = false;
    bool chk[MAX][MAX] = { false };
    vector<pair<int, int>> dot;
    for (int i = 0; i < h - 1; ++i) {
        for (int j = 0; j < w - 1; ++j) {
            if (board[i][j] == '.') continue;
            //2*2 일치
            if (board[i][j] == board[i + 1][j] && board[i][j] == board[i][j + 1] && board[i][j] == board[i + 1][j + 1]) {
                dot.push_back({ i, j });
                dot.push_back({ i + 1, j });
                dot.push_back({ i, j + 1 });
                dot.push_back({ i + 1, j + 1 });
                ret = true;
            }
        }
    }

    for (int i = 0; i < dot.size(); ++i) {
        if (chk[dot[i].first][dot[i].second]) continue;
        chk[dot[i].first][dot[i].second] = true;
        board[dot[i].first][dot[i].second] = '.';
    }

    return ret;
}

void reset(vector<string>& board) {
    for (int col = 0; col < w; ++col) {
        int blank = 0;
        for (int row = h - 1; row >= 0; --row) {
            if (board[row][col] == '.') {
                blank++;
            }
            else {
                if (!blank) continue;
                board[row + blank][col] = board[row][col];
                board[row][col] = '.';
            }
        }
    }
}

int solution(int m, int n, vector<string> board) {
    int answer = 0;
    h = m; w = n;

    //더 조사할 곳이 있을 때까지 진행
    while (solve(board)) {
        //자리 재설정
        reset(board);
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] == '.') answer++;
        }
    }

    return answer;
}