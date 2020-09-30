//2098
#include <bits/stdc++.h>
using namespace std;
#define INF 1000000000
#define MAX 4000005
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

int n, origin;
int cache[16][1<<16];
int d[16][16];

int f(int cur, int chk) {
    if (chk == (1 << n) - 1) {
        if (d[cur][origin] != 0) return d[cur][origin];
        return INF;
    }
    int& ret = cache[cur][chk];
    if (ret != -1) return ret;
    ret = INF;

    for (int i = 0; i < n; ++i) {
        if (chk & (1<<i) || d[cur][i] == 0) continue;
        ret = min(ret, f(i, chk | (1<<i)) + d[cur][i]);
    }
    return ret;
}


int main() {

    cin.tie(nullptr);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    memset(cache, -1, sizeof(cache));
    cin >> n;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> d[i][j];
    cout << f(0, 1);

    return 0;
}