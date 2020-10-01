//1495
#include <bits/stdc++.h>
using namespace std;
#define INF 1000000000
#define MAX 4000005
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

int cache[1001][101];
int n, s, m;
vi a;

int f(int cur, int idx) {
    if (cur < 0) return -INF;
    if (cur > m) return -INF;
    if (idx == n) return cur;
    int& ret = cache[cur][idx];
    if (ret != -2) return ret;
    ret = -1;
    ret = max(ret, max(f(cur - a[idx], idx+1), f(cur+a[idx], idx+1)));
    return ret;
}

int main() {

    cin.tie(nullptr);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    for (int i = 0; i < 1001; ++i)
        for (int j = 0; j < 101; ++j)
            cache[i][j] = -2;

    cin >> n >> s >> m;
    a.resize(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    cout << f(s, 0);

    return 0;
}