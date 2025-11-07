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

    ll S, K; cin >> S >> K;
    
    ll base = S / K, extra = S % K;
    ll ret = 1;
    for (int i=0; i<K; i++) {
        if (i < extra) ret *= (base + 1);
        else ret *= base;
    }
    cout << ret << "\n";

    return 0;
}