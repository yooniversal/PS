//1644
#include <bits/stdc++.h>
using namespace std;
#define INF 1000000001
#define MAX 4000005
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

bool prime[MAX];
vi a;

void eratosthenes() {
    memset(prime, true, sizeof(prime));
    int SN = sqrt(MAX);
    for (int i = 2; i <= SN; i++) {
        if (!prime[i]) continue;
        for (int j = i+i; j < MAX; j += i)
            prime[j] = false;
    }
    prime[1] = false;
}

int main() {

    cin.tie(nullptr);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    eratosthenes();
    int n; cin >> n;

    for (int i = 2; i <= n; ++i)
        if (prime[i]) a.push_back(i);

    int l = 0, r = 0, sum=0, ret=0;
    while (l <= r) {
        if (sum > n) {
            sum -= a[l++];
        }
        else {
            if (sum == n) ++ret;
            if (r == a.size()) break;
            sum += a[r++];
        }
    }
    cout << ret;
        

    return 0;
}