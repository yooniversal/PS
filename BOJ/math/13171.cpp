#include <bits/stdc++.h>
using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

typedef long long ll;
typedef pair<int, int> ii;

const int INF = 1e9;
const int MOD = 1000000007;

ll a, x;
ll aPrime[65];

void initAPrime() {
    ll cur = a % MOD;
    int prime = 1;

    while (prime <= 64) {
        aPrime[prime] = cur;
        cur = (cur * cur) % MOD;
        prime++;
    }
}

ll getResult() {
    ll ret = 1;
    int prime = 1;

    while (x > 0) {
        if (x % 2 == 1) ret = (ret * aPrime[prime]) % MOD;
        x /= 2LL;
        prime++;
    }

    return ret;
}

int main() {
    FASTIO;

    cin >> a >> x;
    initAPrime();

    cout << getResult() << '\n';

    return 0;
}