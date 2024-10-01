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

int n, k;
int cache[25][2];
vector<pair<int, int>> a;

void FASTIO() {
    cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
}

int f(int cur, int bj) {
    if (cur >= n) return INF;
    if (cur == n-1) return 0;
    int& ret = cache[cur][bj];
    if (ret != -1) return ret;
    ret = INF;

    ret = min(ret, f(cur+1, bj) + a[cur].first);
    ret = min(ret, f(cur+2, bj) + a[cur].second);
    if (bj == 1) ret = min(ret, f(cur+3, 0) + k);

    return ret;
}

int main() {
    FASTIO();
    
    for (int i=0; i<25; i++) {
        cache[i][0] = cache[i][1] = -1;
    }

    cin >> n;
    for (int i=0; i<n-1; i++) {
        int u, v; cin >> u >> v;
        a.push_back({u, v});
    }
    cin >> k;

    cout << f(0, 1) << '\n';

    return 0;
}