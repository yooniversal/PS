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

    int percent;
    if (N >= 1000000) {
        percent = 20;
    } else if (N >= 500000) {
        percent = 15;
    } else if (N >= 100000) {
        percent = 10;
    } else {
        percent = 5;
    }

    int give = N * percent / 100;
    int remain = N - give;

    cout << give << " " << remain << "\n";

    return 0;
}