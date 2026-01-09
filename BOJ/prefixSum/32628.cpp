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

    vector<ll> A(N), B(N);
    for (int i=0; i<N; i++) cin >> A[i];
    for (int i=0; i<N; i++) cin >> B[i];

    ll sumA = 0, sumB = 0;
    for (int i=0; i<N; i++) {
        sumA += A[i];
        sumB += B[i];
    }

    vector<ll> removeA(N+1, 0), removeB(N+1, 0);
    for (int i=1; i<=N; i++) {
        removeA[i] = removeA[i-1] + A[N-i];
        removeB[i] = removeB[i-1] + B[N-i];
    }

    ll ans = LLONG_MAX;

    int start = max(0, K-N), end = min(N, K);
    for (int i=start; i<=end; i++) {
        ll A_rem = sumA - removeA[i];
        ll B_rem = sumB - removeB[K-i];
        ans = min(ans, max(A_rem, B_rem));
    }

    cout << ans << '\n';

    return 0;
}