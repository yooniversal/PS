//2580
#include <bits/stdc++.h>
using namespace std;
#define INF 1000000001
#define MAX 5001
#define MOD 1000000
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

bool row[15][15], col[15][15], block[15][15];
int board[15][15];

void dfs(int x, int y) {
    if (board[x][y] != 0) {
        if (y != 8) dfs(x, y + 1);
        else dfs(x + 1, 0);
        return;
    }
    if (x == 9 && y == 0) {
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j)
                cout << board[i][j] << " ";
            cout << '\n';
        }
        exit(0);
    }

    int bn = (x/3)*3 + y/3; //block number
    for (int i = 1; i <= 9; ++i) {
        if (row[x][i]) continue;
        if (col[y][i]) continue;
        if (block[bn][i]) continue;
        row[x][i] = col[y][i] = block[bn][i] = true;
        board[x][y] = i;
        if (y != 8) dfs(x, y + 1);
        else dfs(x + 1, 0);
        board[x][y] = 0;
        row[x][i] = col[y][i] = block[bn][i] = false;
    }
}

int main() {

    cin.tie(nullptr);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    for (int i = 0; i < 9; ++i)
        for (int j = 0; j < 9; ++j) {
            cin >> board[i][j];
            if (board[i][j]) {
                int bn = (i / 3) * 3 + j / 3; //block number;
                row[i][board[i][j]] = true;
                col[j][board[i][j]] = true;
                block[bn][board[i][j]] = true;
            }
        }

    dfs(0, 0);

    return 0;
}