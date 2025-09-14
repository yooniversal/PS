#include <bits/stdc++.h>
using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

typedef long long ll;
typedef pair<int, int> ii;

const int INF = 1e9;
const int MOD = 1000000007;

int main() {
    FASTIO;

    int n; cin >> n;

    int ret = 0;
    ll sum = 1;

    for (int i=1, j=1; i<=j && j<=n;) {
        if (sum == n) {
            ret++;
            sum += ++j;
        } else if (sum > n) {
            sum -= i++;
        } else {
            sum += ++j;
        }
    }

    cout << ret << '\n';

    return 0;
}