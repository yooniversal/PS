//3187
#include <bits/stdc++.h>
using namespace std;
#define INF 1000000001
#define MAX 501
#define MOD 1000000
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

int dx[] = { -1,1,0,0 }, dy[] = { 0,0,1,-1 };
int n, m;
vector<string> a;
bool chk[251][251];
ii tmp;

bool OOB(int x, int y) {
    if (x < 0 || x >= n || y < 0 || y >= m) return true;
    return false;
}

void DFS(int x, int y) {
    if (a[x][y] == 'k') ++tmp.first;
    else if (a[x][y] == 'v') ++tmp.second;

    for (int i = 0; i < 4; ++i) {
        int nx = x + dx[i], ny = y + dy[i];
        if (OOB(nx, ny)) continue;
        if (a[nx][ny] == '#') continue;
        if (chk[nx][ny]) continue;
        chk[nx][ny] = true;
        DFS(nx, ny);
    }
}

int main() {

    cin.tie(nullptr);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        string s; cin >> s;
        a.push_back(s);
    }

    ii ret = { 0, 0 };
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (chk[i][j]) continue;
            chk[i][j] = true;
            tmp = { 0, 0 };
            DFS(i, j);
            if (tmp.first > tmp.second)
                ret.first += tmp.first;
            else ret.second += tmp.second;
        }
    }
    cout << ret.first << ' ' << ret.second;

    return 0;
}