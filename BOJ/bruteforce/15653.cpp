//13460
#include <bits/stdc++.h>
using namespace std;
#define INF 1000000001
#define MAX 520
#define MOD 1000000
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

struct info {
    int rx, ry, bx, by, cnt;
    info() : rx(-1), ry(-1), bx(-1), by(-1), cnt(0) {}
    info(int a, int b, int c, int d, int e) : rx(a), ry(b), bx(c), by(d), cnt(e) {}
};

info first;

int dx[] = { -1,1,0,0 }, dy[] = { 0,0,1,-1 };
int board[11][11];
int ox, oy;
bool chk[12][12][12][12];

int bfs() {
    chk[first.rx][first.ry][first.bx][first.by] = true;
    queue<info> q;
    q.push(first);
    while (!q.empty()) {
        info cur = q.front(); q.pop();
        if ((cur.rx == ox && cur.ry == oy) || (cur.bx == ox && cur.by == oy)) {
            if (cur.rx == cur.bx && cur.ry == cur.by) continue;
            else if (cur.bx == ox && cur.by == oy) continue;
            return cur.cnt;
        }

        //0:ºÏ 1:³² 2:¿ì 3:ÁÂ
        for (int i = 0; i < 4; ++i) {
            int rx = cur.rx, ry = cur.ry;
            int bx = cur.bx, by = cur.by;
            if (i == 0) {
                if (ry == by) {
                    if (rx < bx) {
                        while (board[rx - 1][ry] != 2) {
                            rx += dx[i];
                            if (rx == ox && ry == oy) break;
                        }
                        while (board[bx - 1][by] != 2 && bx - 1 != rx) {
                            bx += dx[i];
                            if (bx == ox && by == oy) break;
                            if (bx - 1 == rx && bx - 1 == ox && by == oy) {
                                --bx;
                                break;
                            }
                        }
                    }
                    else {
                        while (board[bx - 1][by] != 2) {
                            bx += dx[i];
                            if (bx == ox && by == oy) break;
                        }
                        while (board[rx - 1][ry] != 2 && rx - 1 != bx) {
                            rx += dx[i];
                            if (rx == ox && ry == oy) break;
                            if (rx - 1 == bx && rx - 1 == ox && ry == oy) {
                                --rx;
                                break;
                            }
                        }
                    }
                }
                else {
                    while (board[rx - 1][ry] != 2) {
                        rx += dx[i];
                        if (rx == ox && ry == oy) break;
                    }
                    while (board[bx - 1][by] != 2) {
                        bx += dx[i];
                        if (bx == ox && by == oy) break;
                    }
                }
            }
            else if (i == 1) {
                if (ry == by) {
                    if (rx < bx) {
                        while (board[bx + 1][by] != 2) {
                            bx += dx[i];
                            if (bx == ox && by == oy) break;
                        }
                        while (board[rx + 1][ry] != 2 && rx + 1 != bx) {
                            rx += dx[i];
                            if (rx == ox && ry == oy) break;
                            if (rx + 1 == bx && rx + 1 == ox && ry == oy) {
                                ++rx;
                                break;
                            }
                        }
                    }
                    else {
                        while (board[rx + 1][ry] != 2) {
                            rx += dx[i];
                            if (rx == ox && ry == oy) break;
                        }
                        while (board[bx + 1][by] != 2 && bx + 1 != rx) {
                            bx += dx[i];
                            if (bx == ox && by == oy) break;
                            if (bx + 1 == rx && bx + 1 == ox && by == oy) {
                                ++bx;
                                break;
                            }
                        }
                    }
                }
                else {
                    while (board[rx + 1][ry] != 2) {
                        rx += dx[i];
                        if (rx == ox && ry == oy) break;
                    }
                    while (board[bx + 1][by] != 2) {
                        bx += dx[i];
                        if (bx == ox && by == oy) break;
                    }
                }
            }
            else if (i == 2) {
                if (rx == bx) {
                    if (ry < by) {
                        while (board[bx][by + 1] != 2) {
                            by += dy[i];
                            if (bx == ox && by == oy) break;
                        }
                        while (board[rx][ry + 1] != 2 && ry + 1 != by) {
                            ry += dy[i];
                            if (rx == ox && ry == oy) break;
                            if (ry + 1 == by && rx == ox && ry + 1 == oy) {
                                ++ry;
                                break;
                            }
                        }
                    }
                    else {
                        while (board[rx][ry + 1] != 2) {
                            ry += dy[i];
                            if (rx == ox && ry == oy) break;
                        }
                        while (board[bx][by + 1] != 2 && by + 1 != ry) {
                            by += dy[i];
                            if (bx == ox && by == oy) break;
                            if (by + 1 == ry && bx == ox && by + 1 == oy) {
                                ++by;
                                break;
                            }
                        }
                    }
                }
                else {
                    while (board[bx][by + 1] != 2) {
                        by += dy[i];
                        if (bx == ox && by == oy) break;
                    }
                    while (board[rx][ry + 1] != 2) {
                        ry += dy[i];
                        if (rx == ox && ry == oy) break;
                    }
                }
            }
            else if (i == 3) {
                if (rx == bx) {
                    if (ry < by) {
                        while (board[rx][ry - 1] != 2) {
                            ry += dy[i];
                            if (rx == ox && ry == oy) break;
                        }
                        while (board[bx][by - 1] != 2 && by - 1 != ry) {
                            by += dy[i];
                            if (bx == ox && by == oy) break;
                            if (by - 1 == ry && bx == ox && by - 1 == oy) {
                                --by;
                                break;
                            }
                        }
                    }
                    else {
                        while (board[bx][by - 1] != 2) {
                            by += dy[i];
                            if (bx == ox && by == oy) break;
                        }
                        while (board[rx][ry - 1] != 2 && ry - 1 != by) {
                            ry += dy[i];
                            if (rx == ox && ry == oy) break;
                            if (ry - 1 == by && rx == ox && ry - 1 == oy) {
                                --ry;
                                break;
                            }
                        }
                    }
                }
                else {
                    while (board[bx][by - 1] != 2) {
                        by += dy[i];
                        if (bx == ox && by == oy) break;
                    }
                    while (board[rx][ry - 1] != 2) {
                        ry += dy[i];
                        if (rx == ox && ry == oy) break;
                    }
                }
            }
            if (chk[rx][ry][bx][by]) continue;
            chk[rx][ry][bx][by] = true;
            q.push(info(rx, ry, bx, by, cur.cnt + 1));
        }
    }
    return -1;
}

int main() {

    cin.tie(nullptr);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n, m; cin >> n >> m;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j) {
            char a; cin >> a;
            if (a == '#') board[i][j] = 2;
            if (a == 'O') {
                board[i][j] = 1;
                ox = i;
                oy = j;
            }
            if (a == 'R') {
                first.rx = i;
                first.ry = j;
            }
            if (a == 'B') {
                first.bx = i;
                first.by = j;
            }
        }

    cout << bfs();

    return 0;
}