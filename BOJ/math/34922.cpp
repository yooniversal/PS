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

    double w, h, r; cin >> w >> h >> r;

    const double PI = 3.14159265;

    double total = w * h;
    double visible = PI * r * r / 4.0;

    double answer = total - visible;

    cout << fixed << setprecision(6) << answer << '\n';

    return 0;
}