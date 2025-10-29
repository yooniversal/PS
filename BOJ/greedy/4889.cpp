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

int getResult(string& s) {
    int openCnt = 0, ret = 0;
    for (int i=0; i<s.size(); i++) {
        if (s[i] == '{') {
            openCnt++;
        } else {
            if (openCnt > 0) openCnt--;
            else {
                ret++;
                openCnt++;
            }
        }
    }

    return ret + openCnt / 2;
}

int main() {
    FASTIO;

    int cnt = 0;
    while (true) {
        string s; cin >> s;
        if (s[0] == '-') break;
        cout << ++cnt << ". " << getResult(s) << '\n';
    }

    return 0;
}