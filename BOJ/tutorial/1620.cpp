//1620
#include <bits/stdc++.h>
using namespace std;
#define INF 1000000001
#define MAX 100005
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

map<string, int> STI;
map<int, string> ITS;

int main() {

    cin.tie(nullptr);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        string name; cin >> name;
        STI[name] = i;
        ITS[i] = name;
    }
    while (m--) {
        string s; cin >> s;
        if (isupper(s[0])) cout << STI[s] << '\n';
        else cout << ITS[stoi(s)] << '\n';
    }

    return 0;
}