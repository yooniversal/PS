//9507
#include <bits/stdc++.h>
using namespace std;
#define INF 1000000000
#define MAX 4000005
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

ll cache[70];

ll f(int n) {
    if (n < 2)return 1;
    if (n == 2) return 2;
    if (n == 3) return 4;
    ll& ret = cache[n];
    if (ret != -1) return ret;
    ret = f(n - 1) + f(n - 2) + f(n - 3) + f(n - 4);
    return ret;
}

int main() {

    cin.tie(nullptr);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    int t; cin >> t;
    while (t--) {
        memset(cache, -1, sizeof(cache));
        int n; cin >> n;
        cout << f(n) << '\n';
    }

    return 0;
}