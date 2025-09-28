#include <bits/stdc++.h>
using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;

const int INF = 987654321;
const int MOD = 1000000007;

int main() {
    FASTIO;
    
    int n, m; cin >> n >> m;
    vi minMileages;
    for (int i=0; i<n; i++) {
        int P, L; cin >> P >> L;
        
        vi mileages(P);
        for (int j=0; j<P; j++) cin >> mileages[j];
        sort(mileages.begin(), mileages.end());

        if (P < L) minMileages.push_back(1);
        else minMileages.push_back(mileages[P-L]);
    }

    sort(minMileages.begin(), minMileages.end());

    int ret = 0;
    for (auto& minMileage : minMileages) {
        if (m < minMileage) break;
        ret++;
        m -= minMileage;
    }

    cout << ret << '\n';

    return 0;
}