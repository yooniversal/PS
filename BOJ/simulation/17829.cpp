#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <algorithm>
#include <cmath>
using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

typedef long long ll;
typedef pair<int, int> ii;

const int INF = 1e9;
const int MOD = 1000000007;

int n;
vector<vector<int>> a;

int getSecondMax(vector<vector<int>>& arr, int x, int y) {
    int tmp[4] = {arr[x][y], arr[x+1][y], arr[x][y+1], arr[x+1][y+1]};
    sort(tmp, tmp + 4);
    return tmp[2];
}

void pooling() {
    int newSize = n/2;
    int newIndex = 0;
    vector<vector<int>> ret(newSize, vector<int>(newSize));
    
    for (int i=0; i<n; i+=2) {
        for (int j=0; j<n; j+=2) {
            int target = getSecondMax(a, i, j);
            ret[newIndex / newSize][newIndex % newSize] = target;
            newIndex++;
        }
    }

    a = ret;
}

int main() {
    FASTIO;

    cin >> n;
    a.resize(n, vector<int>(n));
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cin >> a[i][j];
        }
    }

    while (n > 1) {
        pooling();
        n /= 2;
    }

    cout << a[0][0] << '\n';

    return 0;
}