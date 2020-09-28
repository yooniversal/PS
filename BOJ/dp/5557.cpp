//5557
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

int n;
ll cache[105][21][2];
vi a;

ll f(int cur, int mr, int oper) {
    if (mr < 0 || mr > 20) return 0;
    if (cur == n - 2) {
        if (mr == a[n - 1]) return 1;
        return 0;
    }
    ll& ret = cache[cur][mr][oper];
    if (ret != -1) return ret;
    ret = f(cur + 1, mr + a[cur + 1], 0) + f(cur + 1, mr - a[cur + 1], 1);
    return ret;
}

int main() {

    cin.tie(nullptr);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    memset(cache, -1, sizeof(cache));

    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    cout << f(0, a[0], 0);

    return 0;
}