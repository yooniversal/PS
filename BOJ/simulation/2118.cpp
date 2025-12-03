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

    int n; cin >> n;
    string s; cin >> s;

    int Lcnt = 0, Scnt = 0;
    int ret = 0;

    for (char c : s) {
        if (c >= '1' && c <= '9') {
            ret++;
        } else if (c == 'L') {
            Lcnt++;
        } else if (c == 'S') {
            Scnt++;
        } else if (c == 'R') {
            if (Lcnt > 0) {
                Lcnt--; ret++;
            } else {
                break;
            }
        } else if (c == 'K') {
            if (Scnt > 0) {
                Scnt--; ret++;
            } else {
                break;
            }
        }
    }

    cout << ret << '\n';

    return 0;
}