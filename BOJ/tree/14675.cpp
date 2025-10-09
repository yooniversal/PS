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

bool isLeaf[100005];
vi e[100005];

int main() {
    FASTIO;

    int n; cin >> n;
    for (int i=0; i<n-1; i++) {
        int a, b; cin >> a >> b;
        e[a].push_back(b);
        e[b].push_back(a);
    }

    int q; cin >> q;
    while (q--) {
        int t, k; cin >> t >> k;
        if (t == 1) {
            if (e[k].size() <= 1) cout << "no" << '\n';
            else cout << "yes" << '\n';
        } else {
            cout << "yes" << '\n';
        }
    }

    return 0;
}