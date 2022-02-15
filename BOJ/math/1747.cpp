//1747
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
const int MAX = 100005, INF = 1000000001, MOD = 9901;

bool prime[5000001];
int n;

void eratosthenes() {
    memset(prime, true, sizeof(prime));
    int SN = sqrt(5000000);
    for (int i = 2; i <= SN; i++) {
        if (!prime[i]) continue;
        for (int j = i + i; j < 5000000; j += i)
            prime[j] = false;
    }
    prime[1] = false;
}

bool check(string s) {
    
    for (int i = 0, j = s.size() - 1; i <= j; ++i, --j) 
        if (s[i] != s[j]) return false;

    return true;
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

    eratosthenes();

    cin >> n;

    for (int i = n; i <= 5000000; ++i) {
        if (prime[i]) {
            if (check(to_string(i))) {

                cout << i << '\n';
                return 0;
            }
        }
    }

	return 0;
}