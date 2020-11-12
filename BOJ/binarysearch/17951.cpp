//17951
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

int n, k;
vi a;

ll binary_search(ll l, ll r) {
    ll ret = INF;
    while (l <= r) {
        ll m = (l + r) / 2, cnt = 1, minsum = INF, tmp = 0;
        for (ll i = 0; i < n && cnt <= k; ++i) {
            tmp += a[i];
            if (i == n - 1) {
                if (tmp > m) {
                    tmp -= a[i];
                    ++cnt;
                }
                minsum = min(minsum, tmp);
                break;
            }
            if (tmp > m) {
                minsum = min(minsum, tmp - a[i]);
                tmp = 0;
                ++cnt;
            }
        }
        if (cnt > k)
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

    cin >> n >> k;
    a.resize(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    cout << binary_search(0, 2000000);

    return 0;
}