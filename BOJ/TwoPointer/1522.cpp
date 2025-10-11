#include <bits/stdc++.h>
using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ii> vii;

const int INF = 987654321;
const int MOD = 1000000007;

int main() {
    FASTIO;

    string s; cin >> s;
    
    int aCnt = 0;
    for (int i=0; i<s.size(); i++) {
        if (s[i] == 'a') aCnt++;
    }

    int maxA = 0;
    int curA = 0, curB = 0;
    int prevI = 0, prevJ = 0;
    for (int i=0, j=aCnt-1, loop=0; loop<s.size(); i=(i+1)%s.size(), j=(j+1)%s.size(), loop++) {
        if (i == 0) {
            for (int t=0; t<aCnt; t++) {
                if (s[t] == 'a') curA++;
                else curB++;
            }
        } else {
            if (s[j] == 'a') curA++;
            else curB++;
        }

        maxA = max(maxA, curA);

        if (s[i] == 'a') curA--;
        else curB--;
    }

    cout << aCnt - maxA << '\n';

    return 0;
}