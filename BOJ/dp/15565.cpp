#include <bits/stdc++.h>
using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

const int INF = 987654321;
const int MOD = 1000000007;

int main() {
    FASTIO;

    int n, k; cin >> n >> k;
    vi a;
    for (int i=0; i<n; i++) {
        int v; cin >> v;
        if (v == 1) a.push_back(i);
    }

    if (a.size() < k) {
        cout << -1 << '\n';
    } else {
        int ret = INF;
        for (int i=0; i<a.size()-(k-1); i++) {
            ret = min(ret, a[i+(k-1)] - a[i] + 1);
        }

        cout << ret << '\n';
    }

    return 0;
}