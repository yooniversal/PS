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

    int N, M;
    ll K;
    cin >> N >> M >> K;

    priority_queue<ll, vector<ll>, greater<ll>> pq;

    for (int i=0; i<M; i++) {
        pq.push(0);
    }

    for (int i=0; i<N; i++) {
        ll t; cin >> t;
        ll cur = pq.top(); pq.pop();
        pq.push(cur + t);
    }

    if (pq.top() <= K) cout << "WAIT" << '\n';
    else cout << "GO" << '\n';

    return 0;
}