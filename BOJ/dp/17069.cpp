//17069
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

int n;
ll cache[33][33][3];
int board[33][33];

bool OOB(int x, int y, int m) {
    if (m == 0 && (x < 0 || x >= n || y < 0 || y >= n - 1)) return true;
    if (m == 1 && (x < 0 || x >= n - 1 || y < 0 || y >= n)) return true;
    if (m == 2 && (x < 0 || x >= n - 1 || y < 0 || y >= n - 1)) return true;
    return false;
}

//m:: 0:가로 1:세로 2:대각선
ll f(int x, int y, int m) {
    if (OOB(x, y, m)) return 0;
    if (m == 0) {
        if (board[x][y] || board[x][y + 1]) return 0;
        if (x == n - 1 && y == n - 2 && !board[n - 1][n - 1]) return 1;
    }
    if (m == 1) {
        if (board[x][y] || board[x + 1][y]) return 0;
        if (x == n - 2 && y == n - 1 && !board[n - 1][n - 1]) return 1;
    }
    if (m == 2) {
        if (board[x][y] || board[x + 1][y] || board[x][y + 1] || board[x + 1][y + 1]) return 0;
        if (x == n - 2 && y == n - 2 && !board[n - 1][n - 1]) return 1;
    }
    ll& ret = cache[x][y][m];
    if (ret != -1) return ret;
    ret = 0;
    if (m == 0) ret = f(x, y + 1, 0) + f(x, y + 1, 2);
    else if (m == 1) ret = f(x + 1, y, 1) + f(x + 1, y, 2);
    else if (m == 2) ret = f(x + 1, y + 1, 0) + f(x + 1, y + 1, 1) + f(x + 1, y + 1, 2);
    return ret;
}

int main() {

    cin.tie(nullptr);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    memset(cache, -1, sizeof(cache));

    cin >> n;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) {
            int a; cin >> a;
            board[i][j] = a;
        }

    cout << f(0, 0, 0);

    return 0;
}