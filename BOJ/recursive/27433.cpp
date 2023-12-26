#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <map>
#include <stack>
#include <algorithm>
#include <cmath>
using namespace std;

typedef long long ll;

const int INF = 987654321;

ll f(ll n) {
    if (n <= 1) return 1;
    return f(n-1) * n;
}

int main() {

    cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

    ll n; cin >> n;
    cout << f(n) << '\n';

    return 0;
}