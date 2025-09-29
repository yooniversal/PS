#include <bits/stdc++.h>
using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;

const int INF = 987654321;
const int MOD = 1000000007;

int main() {
    FASTIO;
    
    ll x, y, w, s; cin >> x >> y >> w >> s;
    
    ll ret = 0;
    if (2*w < s) {
        ret = (x+y) * w;
    } else {
        ret = min(x, y) * s;
        if (w >= s) {
            ret += (max(x, y) - min(x, y)) / 2 * 2 * s;
            ret += ((max(x, y) - min(x, y)) % 2) * w;
        } else {
            ret += (max(x, y) - min(x, y)) * w;
        }
        
    }

    cout << ret << '\n';

    return 0;
}