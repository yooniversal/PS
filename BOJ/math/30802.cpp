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

    vi sizes(6, 0);
    for (int i = 0; i < 6; i++) cin >> sizes[i];

    int t, p; cin >> t >> p;

    ll tshirtSum = 0;
    for (int s : sizes) tshirtSum += (s + t - 1) / t;

    cout << tshirtSum << '\n';
    cout << n/p << " " << n%p << '\n';

    return 0;
}