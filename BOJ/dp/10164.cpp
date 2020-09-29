//10164
#include <bits/stdc++.h>
using namespace std;
#define INF 1000000001
#define MAX 520
#define MOD 1000000
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

int cache[20][20];
int n, m;
int mx, my;

bool OOB(int x, int y) {
    if (x < 0 || x > n || y < 0 || y > m) return true;
    return false;
}

int f(int x, int y, int s, int e) {
    if (OOB(x, y)) return 0;
    if (x == s && y == e) return 1;
    int& ret = cache[x][y];
    if (ret != -1) return ret;
    ret = f(x + 1, y, s, e) + f(x, y + 1, s, e);
    return ret;
}

int main() {

    cin.tie(nullptr);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    memset(cache, -1, sizeof(cache));

    int k; cin >> n >> m >> k;
    if (k != 0) {
        mx = k / m + 1, my = k % m;
        if (my == 0) {
            my = m; --mx;
        }

        int tmp = f(1, 1, mx, my);
        memset(cache, -1, sizeof(cache));
        cout << tmp * f(mx, my, n, m);
    }
    else
        cout << f(1, 1, n, m);

    return 0;
}