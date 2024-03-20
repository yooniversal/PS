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
const int MOD = 1000000007;

int N, M;
int cache[2000005];

void FASTIO() {
    cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
}

int f(int cur) {
    if (cur > M) return INF;
    if (cur == M) return 0;
    int& ret = cache[cur];
    if (ret != -1) return ret;
    ret = INF;

    ret = min(ret, f(cur + 1) + 1);
    ret = min(ret, f(cur * 2) + 1);

    return ret;
}

int main() {
    FASTIO();

    memset(cache, -1, sizeof(cache));
    cin >> N >> M;
    
    cout << f(N) << '\n';

    return 0;
}