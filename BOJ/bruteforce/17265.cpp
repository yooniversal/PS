#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <cmath>
using namespace std;

typedef long long ll;

const int INF = 987654321;
const int MOD = 1000000007;

int dx[] = {1, 0};
int dy[] = {0, 1};
int n;
int a[10][10];
char op[10][10];
int ret_max = -INF, ret_min = INF;

void FASTIO() {
    cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
}

bool OOB(int x, int y) {
    return x>=n || y>=n;
}

int calculate(int a, int b, char oper) {
    if (oper == '+') return a + b;
    if (oper == '-') return a - b;
    return a * b;
}

void dfs(int x, int y, int v, char oper, bool is_max) {
    if (x == n-1 && y == n-1) {
        if (is_max) ret_max = max(ret_max, v);
        else ret_min = min(ret_min, v);
        return;
    }

    for (int i=0; i<2; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if (OOB(nx, ny)) continue;
        if (oper == '.') dfs(nx, ny, v, op[nx][ny], is_max);
        else dfs(nx, ny, calculate(v, a[nx][ny], oper), '.', is_max);
    }
}

int main() {
    FASTIO();

    cin >> n;
    for (int i=0; i<n; i++) for (int j=0; j<n; j++) {
        if ((i + j) % 2 == 0) cin >> a[i][j];
        else cin >> op[i][j];
    }

    dfs(0, 0, a[0][0], '.', true);
    dfs(0, 0, a[0][0], '.', false);

    printf("%d %d\n", ret_max, ret_min);

    return 0;
}