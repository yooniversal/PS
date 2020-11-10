//17945
#include <bits/stdc++.h>
using namespace std;
#define INF 1000000001
#define MAX 2501
#define MOD 1000000
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

int main() {

    cin.tie(nullptr);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int a, b; cin >> a >> b;
    for (int x = -1000; x <= 1000; ++x) {
        if (x * x + 2 * a * x + b == 0) cout << x << ' ';
    }

    return 0;
}