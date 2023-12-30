#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <map>
#include <stack>
#include <algorithm>
#include <cmath>
using namespace std;

typedef long long ll;

const int INF = 987654321;

int n, m, cnt;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
bool chk[605][605];
char a[605][605];

bool OOB(int x, int y) {
    return x<0 || x>=n || y<0 || y>=m;
}

void dfs(int x, int y) {
    for (int i=0; i<4; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if (OOB(nx, ny)) continue;
        if (chk[nx][ny] || a[nx][ny] == 'X') continue;
        if (a[nx][ny] == 'P') cnt++;
        chk[nx][ny] = true;
        dfs(nx, ny);
    }
}

int main() {

    cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

    int sx = -1, sy = -1;

    cin >> n >> m;
    for (int i=0; i<n; i++) {
        string s; cin >> s;
        for (int j=0; j<s.size(); j++) {
            a[i][j] = s[j];
            if (s[j] == 'I') {
                sx = i;
                sy = j;
            }
        }
    }

    chk[sx][sy] = true;
    dfs(sx, sy);

    if (cnt == 0) cout << "TT\n";
    else cout << cnt << '\n';

    return 0;
}