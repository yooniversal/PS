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

    int N, M, K;
    cin >> N >> M >> K;

    double cur = 1.0;

    for (int x = 1; x <= K; x++) {
        cur *= (double)(N - M - (x-1)) / (N - (x-1));
        double Px = 1.0 - cur;
        cout << fixed << setprecision(10) << Px << '\n';
    }

    return 0;
}