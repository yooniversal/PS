//17939
#include <bits/stdc++.h>
using namespace std;
#define INF 1000000001
#define MAX 100001
#define MOD 1000000007
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

int n;
priority_queue<ii> pq; //value, index

int main() {

    cin.tie(nullptr);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n;
    for (int i = 1; i <= n; ++i) {
        int x; cin >> x;
        pq.push({ x, i });
    }

    ll ret = 0, prev = 0;
    while (!pq.empty()) {
        ii cur = pq.top(); pq.pop();
        if (prev < cur.second) {
            ret += cur.first * (cur.second - prev - 1);
            prev = cur.second;
        }
        else
            ret -= cur.first;
        
    }
    cout << ret;

    return 0;
}