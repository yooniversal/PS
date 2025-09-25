#include <bits/stdc++.h>
using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

typedef long long ll;
typedef pair<int, int> ii;

const int INF = 987654321;
const int MOD = 1000000007;

int main() {
    FASTIO;
    
    int n, m; cin >> n >> m;
    vector<int> a;
    for (int i=0; i<n; i++) {
        int v; cin >> v;
        a.push_back(v);
    }
    sort(a.begin(), a.end());

    while (m--) {
        int v; cin >> v;
        int index = lower_bound(a.begin(), a.end(), v) - a.begin();
        
        if (index >= a.size() || a[index] != v) cout << -1 << '\n';
        else cout << index << '\n';
    }

    return 0;
}