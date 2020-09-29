//1806
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

vi a;
vector<ll> pSum;

int main() {

    cin.tie(nullptr);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n, s; cin >> n >> s;
    a.resize(n);
    pSum.resize(n+1, 0);
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 1; i <= n; ++i) pSum[i] = pSum[i - 1] + a[i - 1];
    int ret = INF;
    for (int i = 1; i <= n; ++i) {
        int idx = lower_bound(pSum.begin() + i, pSum.end(), pSum[i - 1] + s) - pSum.begin();
        if (idx != n + 1) ret = min(ret, idx - i + 1);
    }
    if (ret == INF) cout << 0;
    else cout << ret;

    return 0;
}