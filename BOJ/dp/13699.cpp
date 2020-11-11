//13699
#include <bits/stdc++.h>
using namespace std;
#define INF 1000000001
#define MAX 2501
#define MOD 1000000007
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

int n;
ll cache[36];

ll f(int cur) {
    if (cur == 0 || cur == 1) return 1;
    ll& ret = cache[cur];
    if (ret != -1) return ret;
    ret = 0;
    for (int l = 0, r = cur - 1; l<=cur-1, r>=0; ++l, --r) {
        ret += f(l) * f(r);
    }
    return ret;
}

int main() {

    cin.tie(nullptr);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    memset(cache, -1, sizeof(cache));
    cin >> n;
    cout << f(n);

    return 0;
}