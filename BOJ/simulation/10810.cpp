#include <iostream>
#include <string>
#include <cstring>
#include <map>
#include <algorithm>
using namespace std;

int a[105];

int main() {

    cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

    int n, m; cin >> n >> m;
    while (m--) {
        int i, j, k; cin >> i >> j >> k;
        for (int t=i; t<=j; t++) a[t] = k;
    }

    for (int i=1; i<=n; i++) {
        cout << a[i] << " ";
    }
    cout << '\n';

    return 0;
}