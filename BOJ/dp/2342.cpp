//2342
#include <bits/stdc++.h>
using namespace std;
#define INF 1000000001
#define MAX 1000001
#define MOD 1000000
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

int cache[100001][5][5];
vi a;

int f(int cnt, int l, int r) {
    if (cnt == a.size()) return 0;
    int& ret = cache[cnt][l][r];
    if (ret != -1) return ret;
    ret = INF;
    int to = a[cnt], ld = abs(a[cnt] - l), rd = abs(a[cnt] - r);
    int add = 0;

    if (l == 0) ret = min(ret, f(cnt + 1, to, r) + 2);
    else {
        if (ld == 1 || ld == 3) add = 3;
        else if (ld == 2) add = 4;
        else add = 1;
        ret = min(ret, f(cnt + 1, to, r) + add);
    }

    if (r == 0) ret = min(ret, f(cnt + 1, l, to) + 2);
    else {
        if (rd == 1 || rd == 3) add = 3;
        else if (rd == 2) add = 4;
        else add = 1;
        ret = min(ret, f(cnt + 1, l, to) + add);
    }
    
    return ret;
}

int main() {

    cin.tie(nullptr);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    memset(cache, -1, sizeof(cache));

    while (1) {
        int x; cin >> x;
        if (x == 0) break;
        a.push_back(x);
    }

    cout << f(0, 0, 0);

    return 0;
}