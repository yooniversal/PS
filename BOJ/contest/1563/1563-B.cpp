#include <bits/stdc++.h>
using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

typedef long long ll;
typedef pair<int, int> ii;

const int INF = 987654321;
const int MOD = 1000000007;

int main() {
    FASTIO;
    
    int d; cin >> d;
    for (int t=1; t<=d; t++) {
        if ((360 * t) % d == 0) {
            cout << (360 * t) / d << '\n';
            return 0;
        }
    }

    return 0;
}