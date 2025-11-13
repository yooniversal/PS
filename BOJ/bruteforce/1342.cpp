#include <bits/stdc++.h>

using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ii> vii;

int main() {
    FASTIO;

    string s; cin >> s;
    sort(s.begin(), s.end());

    int ret = 0;
    do {
        bool isNotContinuedString = true;
        for (int i = 1; i < s.size(); i++) {
            if (s[i] == s[i - 1]) {
                isNotContinuedString = false;
                break;
            }
        }
        if (isNotContinuedString) ret++;
    } while (next_permutation(s.begin(), s.end()));

    cout << ret << '\n';

    return 0;
}