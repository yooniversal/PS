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

    int n, m; cin >> n >> m;

    if (n == 0) {
        cout << 0 << '\n';
    } else {
        if (n%m == 0) cout << n/m << '\n';
        else cout << n/m + 1 << '\n';
    }

    return 0;
}