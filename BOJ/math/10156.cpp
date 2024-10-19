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

void FASTIO() {
    cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
}

int main() {
    FASTIO();

    int k, n, m; cin >> k >> n >> m;
    if (k * n > m) cout << k * n - m << '\n';
    else cout << 0 << '\n';

    return 0;
}