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

int main() {
    FASTIO;

    int N, K; cin >> N >> K;

    vector<int> A(N);
    for (int i=0; i<N; i++) cin >> A[i];

    for (int i=0; i<K-1; i++) {
        A.push_back(A[i]);
    }

    int cur = 0;
    for (int i=0; i<K; i++) cur += A[i];

    int ans = cur;

    for (int i =K; i<N+K-1; i++) {
        cur += A[i];
        cur -= A[i - K];
        ans = max(ans, cur);
    }

    cout << ans << '\n';

    return 0;
}