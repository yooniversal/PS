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

    int n; cin >> n;
    string s; cin >> s;

    int chickenCnt = 0;
    for (int i=0; i<n; i++) {
        if (s[i] == 'C') chickenCnt++;
    }

    int divideCnt = n - chickenCnt + 1;
    if (chickenCnt % divideCnt != 0) cout << chickenCnt / divideCnt + 1 << '\n';
    else cout << chickenCnt / divideCnt << '\n';

    return 0;
}