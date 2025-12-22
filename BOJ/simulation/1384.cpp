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

    int group = 1;

    while (true) {
        int n; cin >> n;
        if (n == 0) break;

        vector<string> name(n);
        vector<vector<string>> msg(n);

        for (int i=0; i<n; i++) {
            cin >> name[i];
            for (int j=0; j<n-1; j++) {
                string m; cin >> m;
                msg[i].push_back(m);
            }
        }

        cout << "Group " << group++ << '\n';

        bool hasNasty = false;

        for (int i=0; i<n; i++) {
            for (int j=0; j<n-1; j++) {
                if (msg[i][j] == "N") {
                    int writer = (i-j-1+n) % n;
                    cout << name[writer] << " was nasty about " << name[i] << '\n';
                    hasNasty = true;
                }
            }
        }

        if (!hasNasty) {
            cout << "Nobody was nasty" << '\n';
        }

        cout << "\n";
    }

    return 0;
}