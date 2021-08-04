#include <string>
#include <vector>
#include <cmath>
#include <iostream>
using namespace std;
typedef long long ll;

int solve(int idx) {
    if (idx == 1) return 0;
    for (int i = 2; i <= sqrt(idx); ++i) {
        if (idx % i == 0 && idx / i <= 10000000) return idx / i;
    }
    return 1;
}

vector<int> solution(ll begin, ll end) {
    vector<int> answer;
    answer.resize(end - begin + 1, 0);
    for (ll i = begin; i <= end; ++i) {
        int v = solve(i);
        answer[i - begin] = v;
    }

    return answer;
}