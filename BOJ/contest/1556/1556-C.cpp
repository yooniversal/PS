#include <bits/stdc++.h>
using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

typedef long long ll;
typedef pair<int, int> ii;

const int INF = 987654321;
const int MOD = 1000000007;

int dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, 1, -1};
int n, m;
vector<string> a;
bool chk[105][105];
int ret = 0;

bool OOB(int x, int y) {
    return x<0 || x>=n || y<0 || y>=m;
}

void DFS(int x, int y) {
    for (int d=0; d<4; d++) {
        int nx = x+dx[d], ny = y+dy[d];
        if (OOB(nx, ny) || chk[nx][ny] || a[nx][ny] == '.') continue;
        if (a[nx][ny] == 'Y') {
            ret++;
            continue;
        }
        chk[nx][ny] = true;
        DFS(nx, ny);
    }
}

int main() {
    FASTIO;
    
    cin >> n >> m;
    for (int i=0; i<n; i++) {
        string s; cin >> s;
        a.push_back(s);
    }

    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (a[i][j] == '.' || a[i][j] == 'Y') continue;
            chk[i][j] = true;
            DFS(i, j);
            i = n; j = m;
        }
    }

    cout << ret << '\n';

    return 0;
}