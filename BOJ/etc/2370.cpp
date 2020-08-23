//2370

#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <cmath>
#include <algorithm>
#include <map>
using namespace std;
#define INF 987654321
#define MAX 20005
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

int arr[MAX];
bool chk[MAX];
vi lr, L, R;

int main() {

    cin.tie(nullptr);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        int l, r; cin >> l >> r;
        L.push_back(l); R.push_back(r);
        lr.push_back(l); lr.push_back(r);
    }
    sort(lr.begin(), lr.end());
    lr.erase(unique(lr.begin(), lr.end()), lr.end());

    int id = 1;
    for (int i = 0; i < n; i++) {
        int l = lower_bound(lr.begin(), lr.end(), L[i]) - lr.begin();
        int r = lower_bound(lr.begin(), lr.end(), R[i]) - lr.begin();
        for (int j = l; j <= r; j++) {
            arr[j] = id;
        }
        id++;
    }

    int ret = 1; int flag = arr[0];
    chk[flag] = true;
    for (int i = 1; i < 2 * n; i++) {
        int cur = arr[i];
        if (flag != cur && cur && !chk[cur]) ret++;
        chk[cur] = true;
        flag = cur;
    }

    cout << ret;

    return 0;
}