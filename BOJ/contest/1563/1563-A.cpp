#include <bits/stdc++.h>
using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

typedef long long ll;
typedef pair<int, int> ii;

const int INF = 987654321;
const int MOD = 1000000007;

int main() {
    FASTIO;
    
    ll x, y, z; cin >> x >> y >> z;
    ll u, v, w; cin >> u >> v >> w;

    cout << (u / 100 * x) + (v / 50 * y) + (w / 20 * z) << '\n';

    return 0;
}