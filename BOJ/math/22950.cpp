#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <algorithm>
#include <cmath>
using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

typedef long long ll;
typedef pair<int, int> ii;

const int INF = 987654321;
const int MOD = 1000000007;

int main() {
    FASTIO;
    
    int n; cin >> n;
    string s; cin >> s;
    int k; cin >> k;

    for (int i=n-1, j=0; i>=0; i--, j++) {
        if (j >= k) break;
        if (s[i] == '1') {
            cout << "NO\n";
            return 0;
        }
    }

    cout << "YES\n";

    return 0;
}