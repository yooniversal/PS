#include <bits/stdc++.h>

using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ii> vii;
const int INF = 987654321;

bool a[30][30];
int n, m;
int dx[] = {-1, -1, 0}, dy[] = {-1, 0, -1};
int ret;

bool OOB(int x, int y) {
    return x<0 || x>=n || y<0 || y>=m;
}

bool madeSquare(int x, int y) {
    if (x == 0 || y == 0) return false;
    return a[x][y] && a[x-1][y] && a[x][y-1] && a[x-1][y-1];
}

void DFS(int x, int y) {
    int cur = x * m + y;
    
    if (cur == n * m) {
        ret++;
        return;
    }

    int nx = (cur+1) / m, ny = (cur+1) % m;

    DFS(nx, ny);

    a[x][y] = true;
    if (!madeSquare(x, y)) DFS(nx, ny);
    a[x][y] = false;
}

int main() {
    FASTIO;

    cin >> n >> m;
    DFS(0, 0);

    cout << ret << '\n';

    return 0;
}