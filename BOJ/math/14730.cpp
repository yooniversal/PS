#include <bits/stdc++.h>
using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

typedef long long ll;
typedef pair<int, int> ii;

const int INF = 987654321;
const int MOD = 1000000007;

int main() {
    FASTIO;
    
    int n; cin >> n;
    int ret = 0;
    for (int i=0; i<n; i++) {
        int c, k; cin >> c >> k;
        if (k == 0) continue;
        ret += c*k;
    }
    cout << ret << '\n';

    return 0;
}