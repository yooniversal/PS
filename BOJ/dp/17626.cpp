//17626
#include <bits/stdc++.h>
using namespace std;
#define INF 1000000001
#define MAX 501
#define MOD 1000000007
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

int cache[50001];

int f(int cur) {
    if (cur == 0) return 0;
    int& ret = cache[cur];
    if (ret != -1) return ret;
    ret = INF;
    for (int i = 1; i * i <= cur; ++i) {
        ret = min(ret, f(cur - i * i) + 1);
    }
    return ret;
}

int main() {

    cin.tie(nullptr);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    memset(cache, -1, sizeof(cache));
    int n; cin >> n;
    cout << f(n);

    return 0;
}