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

int main() {
    FASTIO;

    int n; cin >> n;
    vi x(n), t(n);
    for (int i=0; i<n; i++) cin >> x[i];
    for (int i=0; i<n; i++) cin >> t[i];

    vi reversePoint(n);
    int curX = x[n-1];
    for (int i=n-1; i>=0; i--) {
        reversePoint[i] = max(curX, t[i]);
        if (n > 0) curX = reversePoint[i] + (x[i] - x[i-1]);
    }

    cout << reversePoint[0] + x[0] << '\n';

    return 0;
}