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

    int N; cin >> N;

    vi a(N);
    for (int i=0; i<N; i++) cin >> a[i];
    sort(a.begin(), a.end());

    cout << a[(N-1) / 2] << '\n';

    return 0;
}