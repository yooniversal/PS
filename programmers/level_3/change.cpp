#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
const int MAX = 100001;
const int MOD = 1000000007;
typedef long long ll;

ll cache[MAX];

int solution(int n, vector<int> money) {
    cache[0] = 1;
    sort(money.begin(), money.end());
    for (int i = 0; i < money.size(); ++i) {
        for (int j = 0; j <= n; ++j) {
            if (j - money[i] >= 0)
                cache[j] += cache[j - money[i]] % MOD;
        }
    }

    return cache[n];
}