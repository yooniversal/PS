#include <bits/stdc++.h>

using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ii> vii;
const int INF = 987654321;

const int MAXN = 100000;
const int MAXP = 200000;

bool isPrime[MAXP + 5];
int special[MAXN + 5];
int pref[MAXN + 5];

void sieve() {
    fill(isPrime, isPrime + MAXP + 5, true);
    isPrime[0] = isPrime[1] = false;

    for (int i = 2; i * i <= MAXP; i++) {
        if (!isPrime[i]) continue;
        for (int j = i * i; j <= MAXP; j += i) {
            isPrime[j] = false;
        }
    }
}

int main() {
    FASTIO;

    sieve();

    for (int p=2; p<=MAXN+1; p++) {
        if (!isPrime[p]) continue;

        int n = p - 1;
        if (n < 1 || n > MAXN) continue;

        string s = to_string(n);
        bool flag = true;

        for (int i=1; i<s.size(); i++) {
            int a = stoi(s.substr(0, i));
            int b = stoi(s.substr(i));
            int val = a * b + 1;

            if (val > MAXP || !isPrime[val]) {
                flag = false;
                break;
            }
        }

        if (flag) special[n] = 1;
    }

    for (int i=1; i<=MAXN; i++) {
        pref[i] = pref[i-1] + special[i];
    }

    int T; cin >> T;
    while (T--) {
        int N; cin >> N;
        cout << pref[N] << '\n';
    }

    return 0;
}