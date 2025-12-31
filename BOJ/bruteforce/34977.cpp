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

    vi L(N);
    for (int i=0; i<N; i++) cin >> L[i];

    for (int K=1; K<=N/2; K++) {
        bool flag = true;
        for (int i=0; i<K; i++) {
            if (L[i] != L[N-K+i]) {
                flag = false;
                break;
            }
        }
        if (flag) {
            cout << "yes" << '\n';
            return 0;
        }
    }

    cout << "no" << '\n';

    return 0;
}