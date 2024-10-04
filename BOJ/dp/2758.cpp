#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <cmath>
using namespace std;

typedef long long ll;

const int INF = 987654321;
const int MOD = 1000000007;

int n, m;
ll cache[15][2005];

void FASTIO() {
    cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
}

ll f(int cur, int v) {
    if (v < (1 << (cur-1))) return 0;
    if (cur <= 1) return 1;
    ll& ret = cache[cur][v];
    if (ret != -1) return ret;
    ret = 0;

    for (int i=v/2; i>=1; i--) {
        ret += f(cur-1, i);
    }

    return ret;
}

int main() {
    FASTIO();

    memset(cache, -1, sizeof(cache));

    int t; cin >> t;
    while (t--) {
        cin >> n >> m;
        int len = 1 << (n-1);
        ll ret = 0;
        for (int i=m; i>=len; i--) {
            ret += f(n, i);
        }
        cout << ret << '\n';
    }

    return 0;
}