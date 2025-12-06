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

int ps1[100005], ps2[100005], ps3[100005];

int main() {
    FASTIO;

    int n, q; cin >> n >> q;

    for (int i=1; i<=n; i++) {
        int x; cin >> x;
        ps1[i] = ps1[i-1];
        ps2[i] = ps2[i-1];
        ps3[i] = ps3[i-1];

        if(x == 1) ps1[i]++;
        else if(x == 2) ps2[i]++;
        else ps3[i]++;
    }

    while (q--) {
        int a, b; cin >> a >> b;
        int r1 = ps1[b] - ps1[a-1];
        int r2 = ps2[b] - ps2[a-1];
        int r3 = ps3[b] - ps3[a-1];
        cout << r1 << " " << r2 << " " << r3 << '\n';
    }

    return 0;
}