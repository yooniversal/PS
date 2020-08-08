//2702

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

int GCD(int a, int b) {
    if (a < b) swap(a, b);

    while (b != 0) {
        int tmp = a % b;
        a = b;
        b = tmp;
    }
    return a;
}

int main() {

    cin.tie(nullptr);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int t; cin >> t;
    while (t--) {
        int a, b; cin >> a >> b;
        cout << (a / GCD(a, b)) * (b / GCD(a, b)) * GCD(a, b) << " " << GCD(a, b) << '\n';
    }

    return 0;
}