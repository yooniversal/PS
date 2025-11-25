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

int main() {
    FASTIO;

    while (true) {
        string s; cin >> s;
        if (s == "end") break;

        if (s == "animal") cout << "Panthera tigris" << '\n';
        else if (s == "tree") cout << "Pinus densiflora" << '\n';
        else cout << "Forsythia koreana" << '\n';
    }

    return 0;
}