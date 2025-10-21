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

const int MAX = 1299709;
bool isPrime[MAX+5];
vi primes;

void initPrimes() {
    memset(isPrime, true, sizeof(isPrime));
    isPrime[1] = false;
    for (int i=2; i*i<=MAX; i++) {
        if (!isPrime[i]) continue;
        for (int j = i*i; j<=MAX; j += i)
            isPrime[j] = false;
    }
    
    for (int i=2; i<=MAX; i++) {
        if (isPrime[i]) primes.push_back(i);
    }
}

int main() {
    FASTIO;

    initPrimes();

    int t; cin >> t;
    while (t--) {
        int k; cin >> k;

        if (isPrime[k]) {
            cout << 0 << '\n';
            continue;
        }

        auto it = upper_bound(primes.begin(), primes.end(), k);
        int right = *it;
        int left = *(it - 1);

        cout << right - left << '\n';
    }

    return 0;
}