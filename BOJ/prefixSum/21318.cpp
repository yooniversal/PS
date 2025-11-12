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

    int n; cin >> n;
    vi a(n), smallerCnt(n, 0);
    for (int i=0; i<n; i++) cin >> a[i];

    for (int i=1; i<n; i++) {
        if (a[i-1] > a[i]) smallerCnt[i] = smallerCnt[i-1] + 1;
        else smallerCnt[i] = smallerCnt[i-1];
    }

    int q; cin >> q;
    while (q--) {
        int x, y; cin >> x >> y;
        x--; y--;
        
        cout << smallerCnt[y] - smallerCnt[x] << '\n';
    }

    return 0;
}