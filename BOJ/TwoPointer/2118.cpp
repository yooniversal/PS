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

ll ps[100005];

int main() {
    FASTIO;

    int n; cin >> n;

    vector<ll> d(n);
    for (int i=0; i<n; i++) cin >> d[i];

    ll C = 0;
    for (int i=0; i<n; i++) C += d[i];

    for (int i=1; i<=n*2; i++) {
        ps[i] = ps[i-1] + d[(i-1) % n];
    }

    ll ret = 0;
    for (int i=0, j=0; i<n; i++) {
        while (j+1 < i+n && ps[j+1] - ps[i] <= C/2) {
            j++;
        }

        ll r = ps[j] - ps[i];
        ret = max(ret, min(r, C - r));
    }

    cout << ret << '\n';

    return 0;
}