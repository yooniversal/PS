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

int prefixSum[1005][1005];

int main() {
    FASTIO;

    int r, c, q; cin >> r >> c >> q;
    vvi a(r, vi(c));
    for (int i=0; i<r; i++) for (int j=0; j<c; j++) cin >> a[i][j];

    for (int i=0; i<r; i++) {
        int sum = 0;
        for (int j=0; j<c; j++) {
            sum += a[i][j];
            prefixSum[i][j] = sum;
        }
    }

    while (q--) {
        int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
        x1--; y1--; x2--; y2--;
        int sum = 0;
        for (int i=x1; i<=x2; i++) {
            if (y1 > 0) sum += prefixSum[i][y2] - prefixSum[i][y1-1];
            else sum += prefixSum[i][y2];
        }

        int cnt = (x2-x1+1) * (y2-y1+1);
        cout << sum / cnt << '\n';
    }

    return 0;
}