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

string getPattern(string& s) {
    string pattern = "";
    map<char, char> charMap;
    int cnt = 0;
    for (int i=0; i<s.size(); i++) {
        if (charMap.find(s[i]) == charMap.end()) {
            charMap[s[i]] = cnt++;
        }
        pattern += charMap[s[i]] + '0';
    }
    return pattern;
}

int main() {
    FASTIO;

    int n; cin >> n;
    vector<string> a(n);
    for (int i=0; i<n; i++) {
        cin >> a[i];
        a[i] = getPattern(a[i]);
    }

    int ret = 0;
    for (int i=0; i<n; i++) {
        for (int j=i+1; j<n; j++) {
            if (a[i] != a[j]) continue;
            ret++;
        }
    }

    cout << ret << '\n';

    return 0;
}