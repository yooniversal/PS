#include <bits/stdc++.h>
using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

typedef long long ll;
typedef pair<int, int> ii;

const int INF = 987654321;
const int MOD = 1000000007;

int main() {
    FASTIO;
    
    for (int n=10; n<=99; n++) {
        int reversedN = (n%10)*10 + n/10;
        if (reversedN % 4 != 0) continue;
        if ((n/10 + (n%10)) % 6 != 0) continue;
        if ((n/10 == 8) && ((n%10) == 8)) continue;
        cout << n << '\n';
        return 0;
    }

    return 0;
}