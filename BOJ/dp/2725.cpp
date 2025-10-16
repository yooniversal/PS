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

int cache[1005];

int GCD(int a, int b) {
    if (b == 0) return a;
    return GCD(b, a%b);
}

int f(int n) {
    if (n == 1) return 3;
    int& ret = cache[n];
    if (ret != -1) return ret;

    int cnt = 0;
    for (int x=0; x<=n; x++) {
        if (GCD(x, n) == 1) cnt++;
    }
    for (int y=0; y<n; y++) {
        if (GCD(n, y) == 1) cnt++;
    }
    ret = f(n-1) + cnt;

    return ret;
}

int main() {
    FASTIO;

    memset(cache, -1, sizeof(cache));

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        cout << f(n) << '\n';
    }

    return 0;
}