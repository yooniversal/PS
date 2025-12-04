#include <bits/stdc++.h>

using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ii> vii;
const int INF = 987654321;

int main() {
    FASTIO;

    int n, m; cin >> n >> m;

    vector<ll> a(n);
    for (int i=0; i<n; i++) cin >> a[i];

    if (m == 0) {
        cout << 0 << '\n';
        return 0;
    }

    ll sum = 0;
    for (int i=0; i<m; i++) sum += a[i];

    ll ret = sum;

    for (int i=0; i<n-m; i++) {
        sum += a[i + m];
        sum -= a[i];
        ret = max(ret, sum);
    }

    cout << ret << '\n';

    return 0;
}