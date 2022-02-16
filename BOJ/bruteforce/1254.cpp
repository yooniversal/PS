//1254
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
const int MAX = 100005, INF = 1000000001, MOD = 9901;

bool check(string s) {

    for (int i = 0, j = s.size() - 1; i <= j; ++i, --j)
        if (s[i] != s[j]) return false;

    return true;
}

int main() {

    cin.tie(nullptr);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    string s; cin >> s;

    int ret = INF;
    for (int i = 0; i < s.size(); ++i) {
        if (check(s.substr(i))) {
            int sz = s.size();
            ret = min(ret, sz+i);
        }
    }
    
    cout << ret << '\n';

    return 0;
}