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

    while (N--) {
        int X; cin >> X;

        vector<string> expr(2*X+1);
        for (int i=0; i < 2*X+1; i++) {
            cin >> expr[i];
        }

        int sum = 0;

        for (int i=0; i<expr.size(); i+=2) {
            if (expr[i] == "!") {
                sum = 10;
                break;
            } else {
                sum += expr[i][0] - '0';
            }
        }

        if (sum >= 10) {
            cout << "!" << '\n';
        } else {
            cout << sum << '\n';
        }
    }

    return 0;
}