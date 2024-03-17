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
int cache[10][10][3];
int d[] = {-1, 0, 1};
int a[10][10];

void FASTIO() {
    cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
}

int f(int cur, int lev, int dir) {
    if (cur >= N - 1) return 0;
    int& ret = cache[cur][lev][dir];
    if (ret != -1) return ret;
    ret = INF;

    for (int i=0; i<3; i++) {
        int n_lev = lev + d[i];
        if (n_lev < 0 || n_lev >= M || i == dir) continue;
        ret = min(ret, f(cur + 1, n_lev, i) + a[cur + 1][n_lev]);
    }
    
    return ret;
}

int main() {
    FASTIO();

    memset(cache, -1, sizeof(cache));
    cin >> N >> M;
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            cin >> a[i][j];
        }
    }

    int ret = INF;
    for (int i=0; i<M; i++) {
        for (int j=0; j<3; j++) {
            ret = min(ret, f(0, i, j) + a[0][i]);
        }
    }
    
    cout << ret << '\n';

    return 0;
}