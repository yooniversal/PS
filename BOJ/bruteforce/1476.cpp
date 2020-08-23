//1476

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
#define MAX 20005
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

int main() {

    cin.tie(nullptr);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int e, s, m; cin >> e >> s >> m;
    int a = 1, b = 1, c = 1;
    ll ret = 1;

    while (!(a == e && b == s && c == m)) {
        a++; b++; c++;
        if (a > 15) a = 1;
        if (b > 28) b = 1;
        if (c > 19) c = 1;
        ret++;
    }
    cout << ret;

    return 0;
}