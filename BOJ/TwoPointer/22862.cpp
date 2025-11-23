#include <bits/stdc++.h>

using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ii> vii;

int main() {
    FASTIO;

    int n, k; cin >> n >> k;
    vi a(n);
    for (int i=0; i<n; i++) cin >> a[i];

    vii b;
    int passCnt = 0;
    for (int i=0; i<n; i++) {
        if (a[i]%2 == 0) {
            b.push_back({a[i], passCnt});
            passCnt = 0;
        } else {
            passCnt++;
        }
    }
    if (b.size() == 0) {
        cout << 0 << '\n';
        return 0;
    }

    b[0].second = 0;

    int curK = 0, ret = 1;
    for (int l=0, r=0; r<b.size();) {
        while (r+1 < b.size() && curK + b[r+1].second <= k) {
            curK += b[++r].second;
            ret = max(ret, r-l+1);
        }

        if (l < r) {
            curK -= b[++l].second;
        } else {
            l++; r++;
        }
    }

    cout << ret << '\n';

    return 0;
}