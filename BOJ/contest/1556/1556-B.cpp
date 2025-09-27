#include <bits/stdc++.h>
using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

typedef long long ll;
typedef pair<int, int> ii;

const int INF = 987654321;
const int MOD = 1000000007;

int main() {
    FASTIO;
    
    ll h1, h2, h3; cin >> h1 >> h2 >> h3;
    ll n; cin >> n;

    ll sum = h1 + h2 + h3;
    ll divided = (n-1)/2;

    if (n % 2 == 0) cout << (h3-h1) * (divided + 1) + sum * divided + sum << '\n';
    else cout << (h3-h1) * divided + sum * divided + sum << '\n';

    return 0;
}