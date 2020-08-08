//2720

#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <cmath>
#include <algorithm>
#include <map>
using namespace std;
#define INF 987654321
#define MAXSIZE 500001
typedef long long ll;

int main() {

    cin.tie(nullptr);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        cout << n / 25 << " ";
        n %= 25;
        cout << n / 10 << " ";
        n %= 10;
        cout << n / 5 << " ";
        n %= 5;
        cout << n << '\n';
    }

    return 0;
}