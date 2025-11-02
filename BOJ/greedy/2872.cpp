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
    vi a(n);
    for (int i=0; i<n; i++) cin >> a[i];

    int target = n, ret = 0;
    for (int i=n-1; i>=0; i--) {
        if (a[i] == target) {
            target--;
        } else {
            ret++;
        }
    }

    cout << ret << '\n';

    return 0;
}