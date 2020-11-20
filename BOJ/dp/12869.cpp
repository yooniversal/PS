//12869
#include <bits/stdc++.h>
using namespace std;
#define INF 1000000000
#define MAX 100005
#define MOD 1000000007
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

int cache[61][61][61];

int f(int a, int b, int c) {
    a = a <= 0 ? 0 : a;
    b = b <= 0 ? 0 : b;
    c = c <= 0 ? 0 : c;
    if (a == 0 && b == 0 && c == 0) return 0;
    int& ret = cache[a][b][c];
    if (ret != -1) return ret;
    ret = INF;
    ret = min(ret, f(a - 9, b - 3, c - 1) + 1);
    ret = min(ret, f(a - 9, b - 1, c - 3) + 1);
    ret = min(ret, f(a - 3, b - 9, c - 1) + 1);
    ret = min(ret, f(a - 1, b - 9, c - 3) + 1);
    ret = min(ret, f(a - 1, b - 3, c - 9) + 1);
    ret = min(ret, f(a - 3, b - 1, c - 9) + 1);
    return ret;
}

int main() {

    cin.tie(nullptr);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    memset(cache, -1, sizeof(cache));
    int n; cin >> n;
    vi a(3, 0);
    for (int i = 0; i < n; ++i) cin >> a[i];
    cout << f(a[0], a[1], a[2]);

    return 0;
}