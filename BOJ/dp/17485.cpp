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

int N, M;
int cache[1005][1005][5];
int a[1005][1005];
int dx[] = {-1, 0, 1};

void FASTIO() {
    cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
}

bool OOB(int x) {
    return x<0 || x>=M;
}

int f(int cur, int x, int prev) {
    if (cur >= N) return 0;
    int& ret = cache[cur][x][prev];
    if (ret != -1) return ret;
    ret = INF;

    for (int d=0; d<3; d++) {
        int nx = x + dx[d];
        if (OOB(nx) || d == prev) continue;
        ret = min(ret, f(cur+1, nx, d) + a[cur][x]);
    }
    
    return ret;
}

int main() {
    FASTIO();

    memset(cache, -1, sizeof(cache));
    cin >> N >> M;
    
    for (int i=0; i<N; i++) for (int j=0; j<M; j++) {
        cin >> a[i][j];
    }

    int ret = INF;
    for (int i=0; i<M; i++) {
        ret = min(ret, f(0, i, 3));
    }

    cout << ret << '\n';

    return 0;
}