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
        string N, M; cin >> N >> M;

        int cnt10 = 0, cnt01 = 0;

        for (int i=0; i<N.size(); i++) {
            if (N[i] == '1' && M[i] == '0') cnt10++;
            else if (N[i] == '0' && M[i] == '1') cnt01++;
        }

        cout << max(cnt10, cnt01) << '\n';
    }

    return 0;
}