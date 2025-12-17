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

    int n, l; cin >> n >> l;

    int pos = 0;
    int t = 0;

    for (int i=0; i<n; i++) {
        int d, r, g; cin >> d >> r >> g;

        t += d - pos;
        pos = d;

        int cycle = r + g;
        int cur = t % cycle;

        if (cur < r) {
            t += r - cur;
        }
    }

    t += l - pos;

    cout << t << '\n';

    return 0;
}