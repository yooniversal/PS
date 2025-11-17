#include <bits/stdc++.h>

using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ii> vii;

bool chk[105];

int main() {
    FASTIO;

    string s; cin >> s;

    int cnt = 0;
    while (cnt < s.size()) {
        vector<pair<string, int>> a;
        for (int i=0; i<s.size(); i++) {
            if (chk[i]) continue;
            chk[i] = true;

            string tmp = "";
            for (int j=0; j<s.size(); j++) {
                if (chk[j]) tmp += s[j];
            }
            a.push_back({tmp, i});

            chk[i] = false;
        }
        sort(a.begin(), a.end());
        chk[a[0].second] = true;

        cout << a[0].first << '\n';
        cnt++;
    }

    return 0;
}