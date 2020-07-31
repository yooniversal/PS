//1453

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
#define MAXSIZE 32001

typedef long long ll;

bool chk[101];
int main() {

    cin.tie(nullptr);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n; cin >> n;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int c; cin >> c;
        if (!chk[c]) chk[c] = true;
        else ans++;
    }
    cout << ans;

    return 0;
}