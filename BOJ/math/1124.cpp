#include <bits/stdc++.h>

using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ii> vii;

const int INF = 987654321;
const int MOD = 1000000007;

bool isPrime[100005];

void initPrime() {
    memset(isPrime, true, sizeof(isPrime));
    isPrime[1] = false;
    for (int i = 2; i * i <= 100005; i++) {
        if (!isPrime[i]) continue;
        for (int j = i * i; j <= 100005; j += i)
            isPrime[j] = false;
    }
}

int main() {
    FASTIO;

    initPrime();
    int a, b; cin >> a >> b;

    int ret = 0;
    for (int i=a; i<=b; i++) {
        int length = 0;
        int current = i;
        for (int j=2; j*j<=current; j++) {
            if (!isPrime[j]) continue;
            while (current % j == 0) {
                length++;
                current /= j;
            }
        }
        if (current > 1) length++;
        if (isPrime[length]) ret++;
    }

    cout << ret << '\n';

    return 0;
}