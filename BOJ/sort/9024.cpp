#include <bits/stdc++.h>

using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ii> vii;
const int INF = 987654321;

int main() {
    FASTIO;

    int t; cin >> t;
    while (t--) {
        int n, K; cin >> n >> K;
        vi a(n);
        for (int i=0; i<n; i++) cin >> a[i];
        sort(a.begin(), a.end());

        int L = 0, R = n-1;
        ll minDiff = 2e8 + 5;
        ll cnt = 0;

        while (L < R) {
            ll sum = a[L] + a[R];
            ll diff = abs(sum - K);

            if (diff < minDiff) {
                cnt = 1;
                minDiff = diff;
            } else if (diff == minDiff) {
                cnt++;
            }

            if (sum < K) L++;
            else R--;
        }

        cout << cnt << '\n';
    }

    return 0;
}