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
    vector<int> a;
    
    int maxx = 0;
    for (int i=0; i<n; i++) {
        int v; cin >> v;
        maxx = max(maxx, v);
        a.push_back(v);
    }

    int ret = 0;
    for (int k=0; k<=maxx; k++) {
        int cnt = 0;
        for (auto& v : a) {
            if (v >= k) cnt++;
        }

        if (cnt >= k) ret = max(ret, k);
    }

    cout << ret << '\n';

    return 0;
}