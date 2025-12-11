#include <bits/stdc++.h>

using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ii> vii;
const int INF = 987654321;

int main() {
    FASTIO;

    ll n, m, k; cin >> n >> m >> k;

    if (k == 0) {
        if ((n == 1 || m == 1) && max(n, m) <= 2) {
            if (n == 1 && m == 1) cout << 0 << '\n';
            else if (n == 1) {
                cout << 0 << " " << 0 << '\n';
            } else {
                cout << 0 << '\n';
                cout << 0 << '\n';
            }
        } else {
            cout << -1 << '\n';
        }
        return 0;
    }
    
    if (n == 1 || m == 1) {
        int maxSize = max(n, m);
        vector<ll> a;
        for (int i=0; i<maxSize; i++) {
            if (i == 0) {
                a.push_back(0);
            } else if (i % 2 != 0) {
                a.push_back(a[i-1] + 1);
            } else {
                a.push_back(a[i-1] + k);
            }
        }

        if (n > 1) {
            for (int i=0; i<a.size(); i++) cout << a[i] << '\n';
        } else {
            for (int i=0; i<a.size(); i++) cout << a[i] << " ";
            cout << '\n';
        }
    } else {
        cout << -1 << '\n';
    }

    return 0;
}