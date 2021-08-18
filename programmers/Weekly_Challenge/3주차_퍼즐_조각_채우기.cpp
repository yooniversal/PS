#include <iostream>
#include <string>
#include <cstring>
#include <vector>
using namespace std;

typedef pair<int, int> ii;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;

int dx[] = { -1,1,0,0 }, dy[] = { 0,0,1,-1 };
int n, block_cnt, ret;
int game_block_flag[51][51], game_block_size[5001], block_flag[51][51];
bool game_board_chk[51][51], flag_chk[5001];
vvi G, T;
vii block[5001];

bool OOB(int x, int y) {
    return x < 0 || x >= n || y < 0 || y >= n;
}

// ���� ���� �� ��ȸ��
void search_GameBlock(int x, int y, int cur) {
    ++game_block_size[cur];
    game_block_flag[x][y] = cur;

    for (int i = 0; i < 4; ++i) {
        int nx = x + dx[i], ny = y + dy[i];
        if (OOB(nx, ny) || G[nx][ny] || game_board_chk[nx][ny]) continue;
        game_board_chk[nx][ny] = true;
        search_GameBlock(nx, ny, cur);
    }
}

// ���̺� �� ��ȸ��
void search_block(int x, int y) {
    T[x][y] = 0;
    block[block_cnt].push_back({ x, y });
    block_flag[x][y] = block_cnt;

    for (int i = 0; i < 4; ++i) {
        int nx = x + dx[i], ny = y + dy[i];
        if (OOB(nx, ny) || T[nx][ny] <= 0) continue;
        search_block(nx, ny);
    }
}

ii rotateXY(int x, int y, int rotation) {

    while (rotation--) {
        if (x == 0) swap(x, y);
        else if (y == 0) {
            x = -x;
            swap(x, y);
        }
        else {
            if (x < 0) {
                if (y < 0) {
                    swap(x, y);
                    y = -y;
                }
                else {
                    x = -x;
                    swap(x, y);
                }
            }
            else {
                if (y < 0) {
                    x = -x;
                    swap(x, y);
                }
                else {
                    swap(x, y);
                    y = -y;
                }
            }
        }
    }

    return { x, y };
}

// �� ��ȣ, ���� ������ �Ǵ� ���� ��ȣ, ȸ�� Ƚ��
// ȸ�� Ƚ���� ���� ��ǥ�� ���� ���� ��� ��ǥ�� ��ȯ
vii rotate(int cur, int criteria, int rotation) {
    vii ret;

    int x = block[cur][criteria].first, y = block[cur][criteria].second; // ���� ��ǥ
    for (auto& next : block[cur]) {
        int nx = next.first, ny = next.second;

        if (cur == 0 && rotation == 1 && x == 0 && y == 2 && criteria == 5) {
            ii xy = rotateXY(nx - x, ny - y, rotation);
            printf("~ nx:%d ny:%d nx-x:%d ny-y:%d => (%d, %d)\n", nx, ny, nx - x, ny - y,
                xy.first, xy.second);
        }
        ret.push_back(rotateXY(nx - x, ny - y, rotation));
    }

    return ret;
}

// cur�� ���� ���Ӻ��忡 ���� true, �ƴϸ� false
int test(int cur, int rotation) {
    for (int x = 0; x < n; ++x) {
        for (int y = 0; y < n; ++y) {
            if (G[x][y]) continue;

            int flag = game_block_flag[x][y];
            if (flag_chk[flag] || game_block_size[flag] != block[cur].size()) continue;

            for (int criteria = 0; criteria < block[cur].size(); ++criteria) {
                auto rotatedXY = rotate(cur, criteria, rotation);

                bool ret = true;

                // ��ǥ������ �� ĭ�� ���´��� üũ
                for (auto& R : rotatedXY) {
                    int nx = x + R.first, ny = y + R.second;
                    if (OOB(nx, ny) || G[nx][ny]) {
                        ret = false;
                        break;
                    }
                }

                if (ret) return flag;
            }

        }
    }

    return -1;
}

void solve() {
    for (int cur = 0; cur < block_cnt; ++cur) {
        // ���� �ִ� 3������ �������� �׽�Ʈ
        for (int rotation = 0; rotation < 4; ++rotation) {
            int flag = test(cur, rotation);

            // ���� ����
            if (flag != -1) {
                flag_chk[flag] = true;

                ret += block[cur].size();

                // ���� �� �� �̻� ���� �ʿ� ����
                break;
            }

        }
    }
}

int solution(vector<vector<int>> game_board, vector<vector<int>> table) {
    n = game_board.size();
    G = game_board, T = table;

    // ���� ���� �� ��ȸ
    int num = 0;
    for (int x = 0; x < n; ++x) {
        for (int y = 0; y < n; ++y) {
            if (G[x][y] || game_board_chk[x][y]) continue;
            game_board_chk[x][y] = true;
            search_GameBlock(x, y, num++);
        }
    }

    /*
    for(int x=0; x<n; ++x) {
        for(int y=0; y<n; ++y) {
            if(G[x][y]) cout << "* ";
            else cout << game_block_flag[x][y] << " ";
        }
        cout << '\n';
    }
    */

    // ���̺� �� �� ������
    for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) {
        if (T[i][j] == 0) T[i][j] = -1;
    }

    // ���̺��� �� ��ȸ
    for (int x = 0; x < n; ++x) {
        for (int y = 0; y < n; ++y) {
            if (T[x][y] <= 0) continue;
            search_block(x, y);
            ++block_cnt;
        }
    }

    /*
    cout << "��:���Ӻ��� �Ʒ�:���̺�\n";
    for(int x=0; x<n; ++x) {
        for(int y=0; y<n; ++y) {
            if(T[x][y] == -1) cout << "# ";
            else cout << block_flag[x][y] << " ";
        }
        cout << '\n';
    }
    cout << "-----------\n";
    */

    // ���Ӻ��忡 �� 0������ üũ
    solve();

    return ret;
}