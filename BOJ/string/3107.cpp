#include <bits/stdc++.h>
using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

typedef long long ll;
typedef pair<int, int> ii;

const int INF = 1e9;
const int MOD = 1000000007;

int main() {
    FASTIO;

    string s; cin >> s;

    vector<string> a;
    string tmp = "";
    for (int i=0; i<s.size(); i++) {
        if (s[i] == ':') {
            a.push_back(tmp);
            tmp = "";
        } else {
            tmp += s[i];
        }

        if (i == s.size()-1) a.push_back(tmp);
    }

    // 앞자리 0 붙이기
    for (int i=0; i<a.size(); i++) {
        if (a[i].size() == 0 || a[i].size() >= 4) continue;
        while (a[i].size() < 4) a[i] = "0" + a[i];
    }

    if (a.size() > 8) {
        // ::a:b:c:d:e:f:g
        // a:b:c:d:e:f:g::
        if (a[0].size() == 0) a.erase(a.begin());
        else a.pop_back();
    } else if (a.size() < 8) {
        // a:b:c:d::f:g:h -> ok
        // a:b::f:g:h -> "" 추가
        int missedCnt = 8 - a.size();
        vector<string> tmp;
        bool inserted = false;
        for (auto& s : a) {
            tmp.push_back(s);
            if (!inserted && s.size() == 0) {
                inserted = true;
                for (int i=0; i<missedCnt; i++) tmp.push_back("");
            }
        }
        a = tmp;
    }

    // "" -> 0000
    // 이외 -> 그대로
    for (int i=0; i<a.size(); i++) {
        if (a[i].size() > 0) cout << a[i];
        else cout << "0000";
        
        if (i < a.size()-1) cout << ":";
    }
    cout << '\n';

    return 0;
}