#include <bits/stdc++.h>

using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ii> vii;

bool chk[10];

int isContinuous(vi& a, int x, int y) {
    vi indices;
    for (int i=0; i<a.size(); i++) {
        if (a[i] == x || a[i] == y) indices.push_back(i);
    }
    int prev = indices[0];
    for (int i=1; i<indices.size(); i++) {
        if (indices[i] != prev+1) return -1;
        prev = indices[i];
    }

    return indices.size();
}

int main() {
    FASTIO;

    int n; cin >> n;
    int cnt = 0;
    vi a(n);
    for (int i=0; i<n; i++) {
        cin >> a[i];
        if (chk[a[i]]) continue;
        chk[a[i]] = true;
        cnt++;
    }

    if (cnt <= 2) {
        cout << n << '\n';
        return 0;
    }

    int ret = 0;
    for (int x=1; x<=9; x++) {
        if (!chk[x]) continue;
        for (int y=x+1; y<=9; y++) {
            if (!chk[y]) continue;
            int len = isContinuous(a, x, y);
            ret = max(ret, len);
        }
    }

    for (int x=1; x<=9; x++) {
        if (!chk[x]) continue;
        int len = isContinuous(a, x, 0);
        ret = max(ret, len);
    }

    cout << ret << '\n';

    return 0;
}