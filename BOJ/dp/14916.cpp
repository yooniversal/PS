//14916
#include <bits/stdc++.h>
using namespace std;
#define INF 1000000001
#define MAX 200005
#define MOD 1000000
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

int cache[100001];
int n;

int f(int cur) {
    if (cur < 0) return INF;
    if (cur == 0) return 0;
    int& ret = cache[cur];
    if (ret != -1) return ret;
    ret = INF;
    ret = min(ret, f(cur - 5) + 1);
    ret = min(ret, f(cur - 2) + 1);
    return ret;
}

int main() {

    cin.tie(nullptr);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    memset(cache, -1, sizeof(cache));
    cin >> n;
    int ret = f(n);
    if (ret == INF) cout << -1;
    else cout << ret;

    return 0;
}