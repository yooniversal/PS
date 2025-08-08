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

int C, R, K;
pair<int, int> order[1000005];
bool chk[1005][1005];
int dx[] = {0, 1, 0, -1}, dy[] = {-1, 0, 1, 0};

void FASTIO() {
    cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
}

bool OOB(int x, int y) {
    return x<0 || x>=C || y<0 || y>=R;
}

int toX(int x) {
    return x + 1;
}

int toY(int y) {
    return R - y;
}

void initOrder() {
    int x = 0, y = R - 1, d = 0;
    int cnt = 1;
    chk[x][y] = true;
    
    while (cnt <= C * R) {
        order[cnt++] = {toX(x), toY(y)};
        // printf("x:%d y:%d d:%d cnt:%d order[%d]={%d, %d}\n", x,y,d,cnt-1,cnt-1,toX(x), toY(y));

        int nx = x + dx[d], ny = y + dy[d];
        int directionChangeCnt = 0;
        while (OOB(nx, ny) || chk[nx][ny]) {
            if (++directionChangeCnt >= 4) break;
            d = (d + 1) % 4;
            nx = x + dx[d], ny = y + dy[d];
        }
        chk[nx][ny] = true;
        x = nx; y = ny;
    }
}

int main() {
    FASTIO();

    cin >> C >> R >> K;

    if (K > C * R) {
        cout << 0 << '\n';
    } else {
        initOrder();
        cout << order[K].first << " " << order[K].second << '\n';
    }

    return 0;
}