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

    int n; cin >> n;

    vi a(n);
    for (int i=0; i<n; i++) cin >> a[i];

    int ret = 0;

    for (int i=1; i<n; i++) {
        for (int j=1; j<n; j++) {
            for (int k=1; k<n; k++) {
                int l = n-i-j-k;
                if (l <= 0) continue;

                int idx = 0;

                int p1 = 1;
                for (int t=0; t<i; t++) p1 *= a[idx++];

                int p2 = 1;
                for (int t=0; t<j; t++) p2 *= a[idx++];

                int p3 = 1;
                for (int t=0; t<k; t++) p3 *= a[idx++];

                int p4 = 1;
                for (int t=0; t<l; t++) p4 *= a[idx++];

                ret = max(ret, p1 + p2 + p3 + p4);
            }
        }
    }

    cout << ret << '\n';

    return 0;
}