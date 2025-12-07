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

int cnt[55];

int main() {
    FASTIO;

    int n; cin >> n;

    for (int i=0; i<n; i++) {
        int x; cin >> x;
        if (x <= 50) cnt[x]++;
    }

    int ret = -1;

    for (int t=0; t<=50; t++) {
        if (cnt[t] == t) ret = t;
    }

    cout << ret << '\n';

    return 0;
}