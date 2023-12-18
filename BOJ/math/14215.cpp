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

int main() {

    cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

    int a, b, c; cin >> a >> b >> c;
    if (a < b) swap(a, b);
    if (a < c) swap(a, c);

    if (a < (b + c)) cout << a + b + c << '\n';
    else cout << 2 * (b + c) - 1 << '\n';

    return 0;
}