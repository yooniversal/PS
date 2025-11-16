#include <bits/stdc++.h>

using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ii> vii;

int main() {
    FASTIO;

    ll k; cin >> k;
    ll base = 0, cnt = 1;
    while (base <= k) {
        cnt <<= 1;
        base += cnt;
    }
    base -= cnt;
    cnt >>= 1;
    if (base == k) {
        base -= cnt; cnt >>= 1;
    }

    int digits = 0;
    while (cnt > 0) {
        cnt >>= 1;
        digits++;
    }

    stack<int> st;
    int target = k - base - 1;
    for (int i=0; i<digits; i++) {
        st.push(target % 2);
        target /= 2;
    }

    while (!st.empty()) {
        if (st.top() == 1) cout << 7;
        else cout << 4;
        st.pop();
    }
    cout << '\n';

    return 0;
}