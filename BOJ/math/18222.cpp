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
    k--;

    int cnt = 0;
    while (k > 0) {
        if (k % 2 == 1) cnt++;
        k /= 2;
    }

    cout << (cnt % 2) << '\n';

    return 0;
}