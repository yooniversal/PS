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

    pair<int, int> x = {INF, -INF};
    pair<int, int> y = {INF, -INF};
    int n; cin >> n;
    for (int i=0; i<n; i++) {
        int a, b; cin >> a >> b;
        x.first = min(x.first, a);
        x.second = max(x.second, a);
        y.first = min(y.first, b);
        y.second = max(y.second, b);
    }

    cout << (x.second - x.first) * (y.second - y.first) << '\n';

    return 0;
}