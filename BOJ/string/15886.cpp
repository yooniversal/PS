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

    int n; cin >> n;
    string s; cin >> s;
    
    int ret = 0;
    for (int i=0; i<n-1; i++){
        if (s[i] == 'E' && s[i+1] == 'W') ret++;
    }
    cout << ret << '\n';

    return 0;
}