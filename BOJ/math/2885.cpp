#include <bits/stdc++.h>

using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ii> vii;

int main() {
    FASTIO;

    int k; cin >> k;

    int targetSize = 1;
    for (int i=1; i<k; i*=2) {
        if (i == k) break;
        targetSize = i;
    }
    targetSize *= 2;
    
    if (targetSize == k) {
        cout << k << " " << 0 << '\n';
        return 0;
    }

    int divideCnt = 0, currentSize = 0, originSize = targetSize;
    while (currentSize < k) {
        divideCnt++;
        targetSize /= 2;
        if (currentSize + targetSize <= k) currentSize += targetSize;
    }

    cout << originSize << " " << divideCnt << '\n';

    return 0;
}