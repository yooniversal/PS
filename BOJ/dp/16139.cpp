#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <map>
#include <stack>
#include <algorithm>
#include <cmath>
using namespace std;

typedef long long ll;

const int INF = 987654321;

string s;

int cnt[200005][30];

void f(char c) {
    for (int i=0; i<s.size(); i++) {
        int flag = s[i] == c ? 1 : 0;
        cnt[i + 1][c - 'a'] = cnt[i][c - 'a'] + flag;
    }
}

int main() {

    cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

    cin >> s;

    for (char c='a'; c<='z'; c++) {
        f(c);
    }

    int q; cin >> q;
    while (q--) {
        char c; cin >> c;
        int l, r; cin >> l >> r;
        l++; r++;
        cout << cnt[r][c - 'a'] - cnt[l - 1][c - 'a'] << '\n';
    }

    return 0;
}