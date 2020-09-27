//1062
#include <bits/stdc++.h>
using namespace std;
#define INF 1000000001
#define MAX 5001
#define MOD 1000000
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

bool a[27];
int conv[27];
vector<string> S;

int main() {

    cin.tie(nullptr);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n, k; cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        string s, ns; cin >> s;
        for (int i = 4; i < s.size() - 4; ++i)
            ns += s[i];
        S.push_back(ns);
    }

    a['a' - 'a'] = a['n' - 'a'] = a['t' - 'a'] = a['i' - 'a'] = a['c' - 'a'] = true;
    k -= 5;
    if (k < 0) {
        cout << 0;
        return 0;
    }

    int cnt = 0;
    for (int i = 0; i < 26; ++i) {
        if (a[i]) continue;
        conv[i] = cnt++;
    }

    string alpha;
    for (int i = 0; i < 21; ++i)
        if (i < k) alpha += '1';
        else alpha += '0';
    reverse(alpha.begin(), alpha.end());

    int ret = 0;
    do {    
        int cnt = 0;
        for (int i = 0; i < S.size(); ++i) {
            bool same = true;
            for (int j = 0; j < S[i].size(); ++j)
                if (!a[S[i][j]-'a'] && alpha[conv[S[i][j]-'a']] != '1') {
                    same = false;
                    break;
                }
            if (same) ++cnt;
        }
        ret = max(ret, cnt);
    } while (next_permutation(alpha.begin(), alpha.end()));
    cout << ret;

    return 0;
}