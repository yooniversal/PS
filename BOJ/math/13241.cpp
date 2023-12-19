#include <iostream>
#include <string>
#include <cstring>
#include <map>
#include <stack>
#include <algorithm>
#include <cmath>
using namespace std;

typedef long long ll;

const int INF = 987654321;

ll gcd(ll a, ll b) {
    if (a < b) swap(a, b);
    
    while (b != 0) {
        ll tmp = a % b;
        a = b;
        b = tmp;
    }

    return a;
}

int main() {

    cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

    ll a, b; cin >> a >> b;
    ll g = gcd(a, b);
    cout << (a/g) * (b/g) * g << '\n';

    return 0;
}