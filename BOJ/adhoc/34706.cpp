#include <bits/stdc++.h>

using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ii> vii;

int cnt[10];

int main() {
    FASTIO;

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        for (int i=1; i<=n; i++) {
            cout << i << " " << (n+1)/2 << '\n';
        }
    }

    return 0;
}