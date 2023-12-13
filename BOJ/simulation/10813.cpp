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

    for (int i=1; i<105; i++) {
        a[i] = i;
    }

    int n, m; cin >> n >> m;
    while (m--) {
        int i, j; cin >> i >> j;
        swap(a[i], a[j]);
    }

    for (int i=1; i<=n; i++) {
        cout << a[i] << " ";
    }
    cout << '\n';

    return 0;
}