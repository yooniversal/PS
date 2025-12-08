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

    while (true) {
        string s; cin >> s;
        if (s == "*") break;

        int n = s.size();
        bool ok = true;

        for (int d=0; d <= n-2 && ok; d++) {
            set<string> st;

            for (int i=0; i+d+1 < n; i++) {
                string tmp = "";
                tmp += s[i];
                tmp += s[i+d+1];

                if (st.find(tmp) != st.end()) {
                    ok = false;
                    break;
                }
                st.insert(tmp);
            }
        }

        if (ok) {
            cout << s << " is surprising." << '\n';
        } else {
            cout << s << " is NOT surprising." << '\n';
        }
    }

    return 0;
}