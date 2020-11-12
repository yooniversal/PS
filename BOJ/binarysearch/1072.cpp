//1072
#include <bits/stdc++.h>
using namespace std;
#define INF 1000000001
#define MAX 2501
#define MOD 1000000
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

ll x, y, z;

ll binary_search(ll l, ll r) {
    ll ret = INF;
    while (l <= r) {
        ll m = (l + r) / 2, tmp = (y+m)*100;
        tmp /= (x + m);
        if (tmp == z)
            l = m + 1;
        else {
            r = m - 1;
            ret = min(ret, m);
        }
    }
    return ret;
}

int main() {

    cin.tie(nullptr);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> x >> y;
    z = y * 100;
    z /= x;
    ll ret = binary_search(1, 1000000000);
    if (ret == INF) cout << -1;
    else cout << ret;

    return 0;
}