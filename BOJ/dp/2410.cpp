//2410
#include <bits/stdc++.h>
using namespace std;
#define INF 1000000001
#define MAX 200005
#define MOD 1000000000
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

int cache[1000001][21];
int n;

int f(int cur, int prev) {
    if (cur < 0) return 0;
    if (cur == 0) return 1;
    if (prev == 0) return 1;
    int& ret = cache[cur][prev];
    if (ret != -1) return ret;
    ret = 0;
    for (int i = prev; i >= 0; --i) {
        ret += f(cur - pow(2, i), i) % MOD;
        ret %= MOD;
    }
    ret %= MOD;
    return ret;
}

int main() {

    cin.tie(nullptr);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    memset(cache, -1, sizeof(cache));
    cin >> n;
    cout << f(n, 20);

    return 0;
}