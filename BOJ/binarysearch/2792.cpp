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

bool jiltwo(vi& jewels, int n, int v) {
    int cnt = 0;
    for (auto& jewel : jewels) {
        if (jewel <= v) cnt++;
        else {
            cnt += jewel / v;
            if (jewel % v != 0) cnt++;
        }
    }
    return cnt <= n;
}

int binarySearch(vi& jewels, int n, int l, int r) {
    int ret = -1;
    int m = (l+r) / 2;

    while (l <= r) {
        m = (l+r) / 2;
        if (jiltwo(jewels, n, m)) {
            r = m - 1;
            ret = m;
        } else {
            l = m + 1;
        }
    }

    return ret;
}

int main() {
    FASTIO;

    int n, m; cin >> n >> m;
    vi jewels(m);
    int maxJewels = 0;
    for (int i=0; i<m; i++) {
        cin >> jewels[i];
        maxJewels = max(maxJewels, jewels[i]);
    }

    if (n == m) {
        cout << maxJewels << '\n';
    } else {
        cout << binarySearch(jewels, n, 1, maxJewels) << '\n';
    }

    return 0;
}