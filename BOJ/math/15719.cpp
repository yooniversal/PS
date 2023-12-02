#include <iostream>
#include <string>
#include <cstring>
#include <map>
#include <algorithm>
using namespace std;

int main() {

    cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

    long long n; cin >> n;

    long long sum = 0;
    for (int i=0; i<n; i++) {
        long long v; cin >> v;
        sum += v;
    }

    cout << sum - (n-1) * n / 2 << '\n';

    return 0;
}