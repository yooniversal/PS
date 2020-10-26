#include <string>
#include <cstring>
#include <vector>
#include <iostream>
using namespace std;
typedef long long ll;

ll cache[31][31];

ll f(int a, int b, int n) {
    if (a == 2 * n) {
        if (b == 0) return 1;
        return 0;
    }
    ll& ret = cache[a][b];
    if (ret != -1) return ret;
    ret = 0;
    ret += f(a + 1, b + 1, n);
    if (b - 1 >= 0) ret += f(a + 1, b - 1, n);
    return ret;
}

int solution(int n) {
    memset(cache, -1, sizeof(cache));
    return f(0, 0, n);
}