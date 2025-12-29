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

    int T; cin >> T;

    while (T--) {
        string s, p; cin >> s >> p;

        int n = s.size();
        int m = p.size();
        int ret = 0;

        for (int i=0; i<n;) {
            if (i+m <= n && s.compare(i, m, p) == 0) {
                i += m;
            } else {
                i++;
            }
            ret++;
        }

        cout << ret << '\n';
    }

    return 0;
}