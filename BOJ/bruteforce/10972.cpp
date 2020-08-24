//10972

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
#define MAX 10001
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

bool isdesc(vi& arr, int idx) {
    for (int i = idx; i < arr.size()-1; i++) {
        if (arr[i] < arr[i + 1]) return false;
    }
    return true;
}

int main() {

    cin.tie(nullptr);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n; cin >> n;
    vi arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < n; i++) {
        if (isdesc(arr, i)) {
            if (i == 0) { cout << "-1"; return 0; }
            sort(arr.begin() + i, arr.end());

            int cur = arr[n-1], idx = n-1;
            for (int j = n-1; j >= i; j--) {
                if (cur > arr[j] && arr[i-1] < arr[j]) {
                    cur = arr[j];
                    idx = j;
                }
            }

            swap(arr[i - 1], arr[idx]);
            break;
        }
    }

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}