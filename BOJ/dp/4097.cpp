#include <bits/stdc++.h>

using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ii> vii;

const int INF = 987654321;
const int MOD = 1000000007;

ll cache[250005];
int n;
vector<ll> a;

ll f(int cur) {
    if (cur >= n-1) return a[n-1];
    ll& ret = cache[cur];
    if (ret != -INF) return ret;
    ret = a[cur];

    ret = max(ret, f(cur+1) + a[cur]);

    return ret;
}

int main() {
    FASTIO;

    while (true) {
        for (int i=0; i<250005; i++) cache[i] = -INF;

        cin >> n;
        if (n == 0) break;
        a.resize(n);
        for (int i=0; i<n; i++) cin >> a[i];

        ll ret = -INF;
        for (int i=0; i<n; i++) ret = max(ret, f(i));
        cout << ret << '\n';
    }

    return 0;
}