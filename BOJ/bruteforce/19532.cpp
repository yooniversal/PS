#include <iostream>
#include <string>
#include <cstring>
#include <map>
#include <algorithm>
#include <cmath>
using namespace std;

typedef long long ll;

int main() {

    cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

    int a, b, c, d, e, f; cin >> a >> b >> c >> d >> e >> f;
    for (int x=-999; x<=999; x++) {
        for (int y=-999; y<=999; y++) {
            if (((a*x + b*y) == c) && ((d*x + e*y) == f)) {
                cout << x << " " << y << '\n';
                return 0;
            }
        }
    }

    return 0;
}