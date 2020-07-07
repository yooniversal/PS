#include <string>
#include <vector>
#include <iostream>

using namespace std;
typedef long long ll;

void swap(ll* a, ll* b) {
    ll tmp = *a;
    *a = *b;
    *b = tmp;
}

ll fc(ll n) {
    return n * (n + 1) / 2;
}

ll solution(int a, int b) {
    ll answer = 0;

    ll la = a;
    ll lb = b;

    if (la > lb) swap(&la, &lb);

    if (la == lb) answer = la;
    else {
        if (la >= 0 && lb >= 0) {
            answer = fc(lb) - fc(la - 1);
        }
        else if (la <= 0 && lb <= 0) {
            la *= -1; lb *= -1;
            answer = fc(la) - fc(lb - 1);
            answer *= -1;
        }
        else {
            la *= -1;
            answer = fc(lb) - fc(la);
        }
    }

    return answer;
}