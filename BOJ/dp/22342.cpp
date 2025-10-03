#include <bits/stdc++.h>
using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

const int INF = 987654321;
const int MOD = 1000000007;

int n, m;
int cache[2005][2005];
vvi a;

int f(int x, int y) {
    if (y <= 0) return a[x][y];
    int& ret = cache[x][y];
    if (ret != -1) return ret;
    ret = 0;

    int rows[] = {x-1, x, x+1};
    for (int& r : rows) {
        if (r < 0 || r >= n) continue;
        ret = max(ret, f(r, y-1) + a[x][y]);
    }

    return ret;
}

int main() {
    FASTIO;

    memset(cache, -1, sizeof(cache));
    
    cin >> n >> m;
    a.resize(n, vi(m, 0));
    for (int i=0; i<n; i++) {
        string s; cin >> s;
        for (int j=0; j<m; j++) {
            a[i][j] = s[j] - '0';
        }
    }

    int ret = 0;
    for (int i=0; i<n; i++) for (int j=0; j<m; j++) {
        ret = max(ret, f(i, j) - a[i][j]);
    }

    cout << ret << '\n';

    return 0;
}