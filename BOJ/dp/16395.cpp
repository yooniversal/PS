//16395
#include <bits/stdc++.h>
using namespace std;
#define INF 1000000001
#define MAX 100005
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

ll cache[31][31];
int n, k;

ll f(int a, int b) {
    if (b == 0 || b == a) return 1;
    ll& ret = cache[a][b];
    if (ret != -1) return ret;
    ret = f(a - 1, b - 1) + f(a - 1, b);
    return ret;
}

int main() {

    cin.tie(nullptr);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    memset(cache, -1, sizeof(cache));
    cin >> n >> k;
    cout << f(n-1, k-1);

    return 0;
}