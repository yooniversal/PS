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

int degree[100005];

int main() {
    FASTIO;

    int n, m; cin >> n >> m;
    for (int i=0; i<m; i++) {
        int u, v; cin >> u >> v;
        degree[u]++;
        degree[v]++;
    }

    bool flag = true;
    for (int i=1; i<=n; i++) {
        if (degree[i] != 2) {
            flag = false;
            break;
        }
    }

    if (m <= n || flag) cout << "Yes" << '\n';
    else cout << "No" << '\n';

    return 0;
}