#include <bits/stdc++.h>

using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ii> vii;

int main() {
    FASTIO;

    int n, m; cin >> n >> m;
    
    vector<string> a(n);
    for (int i=0; i<n; i++) cin >> a[i];
    sort(a.begin(), a.end());

    int ret = 0;
    while (m--) {
        string s; cin >> s;
        auto it = lower_bound(a.begin(), a.end(), s);
        if (it != a.end() && it->substr(0, s.size()) == s) ret++;
    }

    cout << ret << '\n';

    return 0;
}