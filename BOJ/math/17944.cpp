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

    int n, t; cin >> n >> t;

    int cycle = 4LL * n - 2;
    int a = (t - 1) % cycle + 1;

    int ret = 0;
    if (a <= 2 * n) ret = a;
    else ret = 4 * n - a;

    cout << ret << '\n';

    return 0;
}