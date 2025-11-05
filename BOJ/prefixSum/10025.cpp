#include <bits/stdc++.h>

using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ii> vii;

int ice[2000005];
ll prefixSum[2000005];

int main() {
    FASTIO;

    int n, k; cin >> n >> k;
    int maxX = 0;
    for (int i=0; i<n; i++) {
        int g, x; cin >> g >> x;
        maxX = max(maxX, x);
        ice[x] = g;
    }


    for (int x=1; x<=maxX; x++)
        prefixSum[x] = prefixSum[x-1] + ice[x];

    ll ret = 0;
    for (int x=0; x<=maxX; x++) {
        int l = max(0, x-k), r = min(x+k, maxX);
        ret = max(
            ret,
            prefixSum[r] - (l > 0 ? prefixSum[l-1] : 0)
        );
    }

    cout << ret << '\n';

    return 0;
}