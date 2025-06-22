#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <map>
#include <stack>
#include <algorithm>
#include <cmath>
#include <queue>
using namespace std;

typedef long long ll;

const int INF = 987654321;
const int MOD = 1000000007;

int dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, 1, -1};
int R, C, K;
char a[10][10];
bool chk[10][10];
int ret;

void FASTIO() {
    cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
}

bool OOB(int x, int y) {
    return x<0 || x>=R || y<0 || y>=C;
}

void DFS(int x, int y, int cnt) {
    if (cnt > K) return;
    // printf("x:%d y:%d cnt:%d\n",x,y,cnt);
    if (x == 0 && y == C-1) {
        if (cnt == K) ret++;
        return;
    }

    for (int i=0; i<4; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if (OOB(nx, ny) || chk[nx][ny] || a[nx][ny] == 'T') continue;
        chk[nx][ny] = true;
        DFS(nx, ny, cnt + 1);
        chk[nx][ny] = false;
    }
}

int main() {
    FASTIO();

    cin >> R >> C >> K;
    for (int i=0; i<R; i++) for (int j=0; j<C; j++) {
        cin >> a[i][j];
    }
    
    
    chk[R-1][0] = true;
    DFS(R-1, 0, 1);

    cout << ret << '\n';

    return 0;
}