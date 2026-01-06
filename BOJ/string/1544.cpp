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

string canonical(const string& s) {
    string best = s;
    for (int i=1; i<s.size(); i++) {
        string rotated = s.substr(i) + s.substr(0, i);
        if (rotated < best) {
            best = rotated;
        }
    }
    return best;
}

int main() {
    FASTIO;

    int N; cin >> N;
    set<string> cache;

    while(N--) {
        string s; cin >> s;
        cache.insert(canonical(s));
    }

    cout << cache.size() << '\n';

    return 0;
}