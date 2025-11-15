#include <bits/stdc++.h>

using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ii> vii;

string s;
map<char, int> convertMap = {{'H', 1}, {'C', 12}, {'O', 16}};

ii parseBracket(int start) {
    int score = 0;

    for (int i=start; i<s.size(); i++) {
        if ('A' <= s[i] && s[i] <= 'Z') {
            if (i < s.size()-1 && ('0' <= s[i+1] && s[i+1] <= '9')) {
                score += convertMap[s[i]] * (s[i+1] - '0');
                i++;
            } else {
                score += convertMap[s[i]];
            }
        } else if (s[i] == '(') {
            ii nextRet = parseBracket(i+1);
            score += nextRet.first;
            i = nextRet.second;
        } else {
            if (i < s.size()-1 && ('0' <= s[i+1] && s[i+1] <= '9')) {
                return {score * (s[i+1] - '0'), i+1};
            } else {
                return {score, i};
            }
        }
    }

    return {score, s.size()};
}

int main() {
    FASTIO;

    cin >> s;
    cout << parseBracket(0).first << '\n';

    return 0;
}