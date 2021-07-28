#include <string>
#include <vector>
#include <iostream>
using namespace std;

int num[18];

void solve(int& n) {
    int tmp = 1, cnt = 0;
    while (tmp <= n) {
        ++cnt;
        tmp *= 3;
    }
    tmp /= 3;
    num[--cnt] = n / tmp;
    n %= tmp;
}

int solution(int n) {
    int answer = 0;

    while (n) { solve(n); };

    for (int i = 17; i >= 0; --i)
        if (num[i] != 0) {
            for (int j = 0, k = i; k >= 0; ++j, --k) {
                int t = 1;
                for (int p = 0; p < j; ++p) t *= 3;
                t *= num[k];
                answer += t;
            }
            break;
        }

    return answer;
}