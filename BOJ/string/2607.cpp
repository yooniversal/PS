#include <bits/stdc++.h>

using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ii> vii;
const int INF = 987654321;

int base[26], cnt[26];

int main() {
    FASTIO;

    int n; cin >> n;

    string baseWord; cin >> baseWord;
    for (char c : baseWord) base[c - 'A']++;

    int ret = 0;

    for (int i=0; i<n-1; i++) {
        string word; cin >> word;
        memset(cnt, 0, sizeof(cnt));
        for (char c : word) cnt[c - 'A']++;

        int diff = 0;
        for (int j=0; j<26; j++) diff += abs(base[j] - cnt[j]);

        int lenDiff = abs((int)baseWord.size() - (int)word.size());

        if (lenDiff >= 2) continue;
        if (lenDiff == 0) {
            if (diff == 0 || diff == 2) ret++;
        } else {
            if (diff == 1) ret++;
        }
    }

    cout << ret << '\n';

    return 0;
}