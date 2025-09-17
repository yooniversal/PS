#include <bits/stdc++.h>
using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

typedef long long ll;
typedef pair<int, int> ii;

const int INF = 1e9;
const int MOD = 1000000007;

vector<int> score;
map<int, string> ranks;

int main() {
    FASTIO;

    int n, m; cin >> n >> m;
    for (int i=0; i<n; i++) {
        string s; int v; cin >> s >> v;
        score.push_back(v);
        if (ranks[v] == "") ranks[v] = s;
    }

    while (m--) {
        int v; cin >> v;
        int index = lower_bound(score.begin(), score.end(), v) - score.begin();
        cout << ranks[score[index]] << '\n';
    }

    return 0;
}