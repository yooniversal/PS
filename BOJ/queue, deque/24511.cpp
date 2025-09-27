#include <bits/stdc++.h>
using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

typedef long long ll;
typedef pair<int, int> ii;

const int INF = 987654321;
const int MOD = 1000000007;

int main() {
    FASTIO;
    
    int n; cin >> n;
    vector<int> a(n);
    for (int i=0; i<n; i++) cin >> a[i];

    vector<int> b(n);
    for (int i=0; i<n; i++) cin >> b[i];

    queue<int> q;
    for (int i=n-1; i>=0; i--) {
        if (a[i] == 0) q.push(b[i]);
    }

    int m; cin >> m;
    for (int i=0; i<m; i++) {
        int v; cin >> v;
        q.push(v);
    }

    for (int i=0; i<m; i++) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << '\n';

    return 0;
}