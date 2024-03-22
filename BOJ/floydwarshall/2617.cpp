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

int N, M;
int d[101][101];
bool chk[101];

void FASTIO() {
    cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
}

void init() {
    for (int i=0; i<101; i++) {
        for (int j=0; j<101; j++) {
            if (i != j) d[i][j] = INF;
        }
    }
}

void floyd() {
    for (int k=1; k<=N; k++) {
        for (int i=1; i<=N; i++) {
            for (int j=1; j<=N; j++) {
                if (d[i][j] > d[i][k] + d[k][j])
                    d[i][j] = d[i][k] + d[k][j];
            }
        }
    }
}

int main() {
    FASTIO();
    init();

    cin >> N >> M;
    while (M--) {
        int u, v; cin >> u >> v;
        d[v][u] = 1;
    }

    floyd();

    int ret = 0;
    for (int i=1; i<=N; i++) {
        int cnt = 0;
        for (int j=1; j<=N; j++) {
            if (d[i][j] == 0 || d[i][j] == INF) continue;
            cnt++;
        }
        if (cnt >= (N + 1) / 2) {
            if (chk[i]) continue;
            chk[i] = true;
            ret++;
        }
    }

    for (int i=1; i<=N; i++) {
        int cnt = 0;
        for (int j=1; j<=N; j++) {
            if (d[j][i] == 0 || d[j][i] == INF) continue;
            cnt++;
        }
        if (cnt >= (N + 1) / 2) {
            if (chk[i]) continue;
            chk[i] = true;
            ret++;
        }
    }

    // for (int i=1; i<=N; i++) {
    //     printf("[%d] ", i);
    //     for (int j=1; j<=N; j++) {
    //         if (d[i][j] == INF) cout << "INF ";
    //         else printf("%-3d ", d[i][j]);
    //     }
    //     cout << '\n';
    // }
    
    cout << ret << '\n';

    return 0;
}