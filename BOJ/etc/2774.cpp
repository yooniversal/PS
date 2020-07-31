//2774

#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <cmath>
#include <algorithm>
#include <map>
using namespace std;
#define MAXSIZE 32001

typedef long long ll;

int main() {

    cin.tie(nullptr);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int t; cin >> t;
    while (t--) {
        string s; cin >> s;
        bool chk[10];
        memset(chk, false, sizeof(chk));
        int ans = 0;
        for (int i = 0; i < s.size(); i++) {
            chk[s[i] - '0'] = true;
        }

        for (int i = 0; i < 10; i++)
            if (chk[i]) ans++;

        cout << ans << '\n';
    }

    return 0;
}