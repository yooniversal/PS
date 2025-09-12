#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <algorithm>
#include <cmath>
using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

typedef long long ll;
typedef pair<int, int> ii;

const int INF = 1e9;
const int MOD = 1000000007;

int getParent(int v) {
    if (v > 1) return v/2;
    return 1;
}

int LCA(int a, int b) {
    while (!(a == b || getParent(a) == getParent(b))) {
        if (a < b) b = getParent(b);
        else a = getParent(a);
    }

    if (a == b) return a;
    return getParent(a);
}

int main() {
    FASTIO;

    int t; cin >> t;
    while (t--) {
        int a, b; cin >> a >> b;
        cout << 10 * LCA(a, b) << '\n';
    }

    return 0;
}