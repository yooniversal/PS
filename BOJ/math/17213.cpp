#include <bits/stdc++.h>
using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;

const int INF = 987654321;
const int MOD = 1000000007;

ll combination(int n, int r) {
    ll ret = 1;
    for (int i = 1; i <= r; i++) {
        ret = ret * (n - r + i) / i;
    }
    return ret;
}

int main() {
    FASTIO;
    
    int n, m; cin >> n >> m;
    int r = m - n;
    cout << combination(n+r-1, r) << '\n';

    return 0;
}