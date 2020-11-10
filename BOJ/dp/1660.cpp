//1660
#include <bits/stdc++.h>
using namespace std;
#define INF 1000000001
#define MAX 100001
#define MOD 1000000
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

int cache[123], cache2[123], cache3[300001];
int n;

int sum(int n) {
    if (n == 1) return 1;
    int& ret = cache[n];
    if (ret != -1) return ret;
    ret = 0;
    ret = sum(n - 1) + n;
    return ret;
}

int ssum(int n) {
    if (n == 1) return 1;
    int& ret = cache2[n];
    if (ret != -1) return ret;
    ret = 0;
    ret = ssum(n - 1) + sum(n);
    return ret;
}

int f(int cur) {
    if (cur == 0) return 0;
    int& ret = cache3[cur];
    if (ret != -1) return ret;
    ret = INF;
    for (int i = 1; ssum(i) <= cur; ++i)
        ret = min(ret, f(cur - ssum(i)) + 1);
    return ret;
}

int main() {

    cin.tie(nullptr);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    memset(cache, -1, sizeof(cache));
    memset(cache2, -1, sizeof(cache2));
    memset(cache3, -1, sizeof(cache3));
    cin >> n;
    cout << f(n);

    return 0;
}