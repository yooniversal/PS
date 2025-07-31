#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <map>
#include <stack>
#include <algorithm>
#include <cmath>
#include <queue>
using namespace std;

typedef long long ll;

const int INF = 987654321;
const int MOD = 1000000007;

int n, m;
vector<string> a;

void FASTIO() {
    cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
}

vector<string> parseWords(string& s) { 
    vector<string> ret;
    if (s.size() <= 1) return ret;

    string tmp = "";
    for (int i=0; i<s.size(); i++) {
        if (s[i] == '#') {
            if (tmp.size() > 1) ret.push_back(tmp);
            tmp = "";
        } else {
            tmp += s[i];
        }
    }

    if (tmp.size() > 1) ret.push_back(tmp);


    return ret;
}

int main() {
    FASTIO();

    cin >> n >> m;
    for (int i=0; i<n; i++) {
        string s; cin >> s;
        a.push_back(s);
    }

    vector<string> allWords;

    for (int i=0; i<n; i++) {
        vector<string> wordsFromRows = parseWords(a[i]);
        for (auto& word : wordsFromRows) {
            allWords.push_back(word);
        }
    }

    for (int i=0; i<m; i++) {
        string s = "";
        for (int j=0; j<n; j++) {
            s += a[j][i];
        }

        vector<string> wordsFromCols = parseWords(s);
        for (auto& word : wordsFromCols) {
            allWords.push_back(word);
        }
    }

    sort(allWords.begin(), allWords.end());

    cout << allWords[0] << '\n';

    return 0;
}