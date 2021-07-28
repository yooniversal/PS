#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;

ll pac[21];
bool use[21];

void makePAC() {
    ll tmp = 1;
    for (int i = 1; i <= 20; ++i) {
        tmp *= i;
        pac[i] = tmp;
    }
}

int cntToN(int n) {
    int cnt = 0;
    for (int i = 1; i <= 20; ++i) {
        if (use[i]) continue;
        if (n == cnt++) return i;
    }
}

vector<int> solution(int n, ll k) {
    vector<int> answer;

    makePAC();
    int size = n - 1;
    ll turn = k;
    while (turn > 1) {
        ll M = pac[size--];
        ll Q = (turn - 1) / M;
        turn = (turn - 1) % M + 1;
        int num = cntToN(Q);
        use[num] = true;
        answer.push_back(num);
    }

    for (int i = 1; i <= n && answer.size() != n; ++i)
        if (use[i]) continue;
        else answer.push_back(i);

    return answer;
}