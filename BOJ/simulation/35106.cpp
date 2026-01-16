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

int cnt[4];

int main() {
    FASTIO;

    int N; cin >> N;

    for (int i=0; i<N*3; i++) {
        int x; cin >> x;
        cnt[x]++;
    }

    int should_be = -1;
    int actual = -1;

    for (int i=1; i<=3; i++) {
        if (cnt[i] < N) should_be = i;
        if (cnt[i] > N) actual = i;
    }

    cout << should_be << '\n';
    cout << actual << '\n';

    return 0;
}