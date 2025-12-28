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

    string s; cin >> s;

    int n = s.size();
    vector<bool> bulb(n+1);

    for (int i=1; i<=n; i++) {
        bulb[i] = (s[i-1] == 'Y');
    }

    int cnt = 0;
    for (int i=1; i<=n; i++) {
        if (bulb[i]) {
            cnt++;
            for (int j=i; j<=n; j+=i) {
                bulb[j] = !bulb[j];
            }
        }
    }

    for (int i=1; i<=n; i++) {
        if (bulb[i]) {
            cout << -1 << '\n';
            return 0;
        }
    }

    cout << cnt << '\n';

    return 0;
}