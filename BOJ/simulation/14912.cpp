#include <iostream>
#include <string>
#include <cstring>
#include <map>
#include <algorithm>
using namespace std;

int cnt[10];

int main() {

    cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

    int n, k; cin >> n >> k;
    
    for (int i=1; i<=n; i++) {
        int t = i;
        while (t != 0) {
            cnt[t % 10]++;
            t /= 10;
        }
    }

    cout << cnt[k] << '\n';

    return 0;
}