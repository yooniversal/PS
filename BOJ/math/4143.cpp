#include <iostream>
#include <string>
#include <cstring>
#include <map>
#include <algorithm>
#include <cmath>
using namespace std;

typedef long long ll;

ll getPrime(ll n) {
    if (n == 0 || n == 1) return 2;
    for (ll i=n; ; i++) {
        bool flag = true;
        for (ll j=2; j<=sqrt(i); j++) {
            if (i % j == 0) {
                flag = false;
                break;
            }
        }
        if (flag) return i;
    }
    return -1;
}

int main() {

    cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

    int t; cin >> t;
    while (t--) {
        ll n; cin >> n;
        cout << getPrime(n) << '\n';
    }

    return 0;
}