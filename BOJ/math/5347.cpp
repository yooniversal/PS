#include <bits/stdc++.h>
using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

typedef long long ll;
typedef pair<int, int> ii;

const int INF = 987654321;
const int MOD = 1000000007;

ll gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main() {
    FASTIO;
    
    int t; cin >> t;
    while (t--) {
        ll a, b; cin >> a >> b;
        if (a < b) {
            ll tmp = a;
            a = b;
            b = tmp;
        }
        cout << a*b / gcd(a, b) << '\n';
    }

    return 0;
}