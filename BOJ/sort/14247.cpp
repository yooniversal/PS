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

int main() {
    FASTIO;

    int n; cin >> n;
    vii a;
    for (int i=0; i<n; i++) {
        int v; cin >> v;
        a.push_back({0, v});
    }
    for (int i=0; i<n; i++) {
        int v; cin >> v;
        a[i].first = v;
    }
    sort(a.begin(), a.end());

    ll ret = 0;
    for (int i=0; i<n; i++) {
        ret += a[i].second + a[i].first * i * 1LL;
    }

    cout << ret << '\n';

    return 0;
}