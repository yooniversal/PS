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

bool chk[1005];

int main() {
    FASTIO;

    int n; cin >> n;
    vi a(n);
    for (int i=0; i<n; i++) cin >> a[i];
    sort(a.begin(), a.end());

    int ret = 0, used = 0;
    while (used < a.size()) {
        int prev = -1;
        for (int i=0; i<n; i++) {
            if (chk[i] || a[i] == prev) continue;
            chk[i] = true;
            prev = a[i];
            used++;
        }

        ret++;
    }
    cout << ret << '\n';

    return 0;
}