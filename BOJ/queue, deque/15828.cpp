#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <cmath>
using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

typedef long long ll;
typedef pair<int, int> ii;

const int INF = 987654321;
const int MOD = 1000000007;



int main() {
    FASTIO;
    
    int n; cin >> n;
    queue<int> q;
    
    while (true) {
        int v; cin >> v;
        if (v == -1) break;

        if (v == 0) q.pop();
        else {
            if (q.size() >= n) continue;
            q.push(v);
        }
    }

    if (q.empty()) {
        cout << "empty\n";
        return 0;
    }

    while (!q.empty()) {
        int v = q.front(); q.pop();
        cout << v << " ";
    }
    cout << '\n';

    return 0;
}