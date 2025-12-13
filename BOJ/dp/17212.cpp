#include <bits/stdc++.h>

using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ii> vii;
const int INF = 987654321;

int cache[100005];
int coins[] = {7, 5, 2, 1};

int f(int cur) {
    if (cur <= 0) return 0;
    int& ret = cache[cur];
    if (ret != -1) return ret;
    ret = INF;

    for (auto& coin : coins) {
        if (cur >= coin) ret = min(ret, f(cur - coin) + 1);
    }

    return ret;
}

int main() {
    FASTIO;

    memset(cache, -1, sizeof(cache));
    int n; cin >> n;
    cout << f(n) << '\n';

    return 0;
}