//16198
#include <bits/stdc++.h>
using namespace std;
#define INF 1000000001
#define MAX 100005
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

bool chk[11];
int n, ret;
vi a;

void DFS(int cnt, int val) {
    if (cnt == n - 2) {
        ret = max(ret, val);
        return;
    }

    for (int i = 1; i <= n - 2; ++i) {
        if (chk[i]) continue;
        chk[i] = true;
        int l = i - 1, r = i + 1;
        while (chk[l]) { l--; }
        while (chk[r]) { r++; }
        DFS(cnt + 1, val + a[l] * a[r]);
        chk[i] = false;
    }
}

int main() {

    cin.tie(nullptr);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 1; i <= n - 2; ++i) {
        chk[i] = true;
        DFS(1, a[i-1]*a[i+1]);
        chk[i] = false;
    }
    cout << ret;

    return 0;
}