#include <bits/stdc++.h>
using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

typedef long long ll;
typedef pair<int, int> ii;

const int INF = 1e9;
const int MOD = 1000000007;

bool kSoinsoo(int n, int k) {
    for (int i=2; i<=k; i++) {
        if (i > n) break;
        while (n % i == 0) n /= i;
    }
    return n <= k;
}

int main() {
    FASTIO;

    int n, k; cin >> n >> k;

    int ret = 0;
    for (int i=1; i<=n; i++) {
        if (kSoinsoo(i, k)) ret++;
    }

    cout << ret << '\n';

    return 0;
}