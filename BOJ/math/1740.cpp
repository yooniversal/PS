#include <iostream>
#include <string>
#include <cstring>
#include <map>
#include <algorithm>
using namespace std;

typedef long long ll;

int main() {

    cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

    ll n; cin >> n;

    string two_digits = "";
    while (n != 0) {
        two_digits += to_string(n % 2);
        n /= 2;
    }
    reverse(two_digits.begin(), two_digits.end());

    ll v = 1;
    for (int i=0; i<two_digits.size()-1; i++) v *= 3;

    ll ret = 0;
    for (int i=0; i<two_digits.size(); i++) {
        ret += (two_digits[i] - '0') * v;
        v /= 3L;
    }

    cout << ret << '\n';

    return 0;
}