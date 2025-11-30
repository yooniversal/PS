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

    int g; cin >> g;

    bool flag = true;
    for (ll cur=1; cur<=65535;cur++) {
        if (cur*cur - g <= 0) continue;
        ll x2 = cur*cur - g;
        ll x = (ll) sqrt(x2);
        
        if (x*x == x2) {
            flag = false;
            cout << cur << '\n';
        }
    }

    if (flag) cout << -1 << '\n';

    return 0;
}