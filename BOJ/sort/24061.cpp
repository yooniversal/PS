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

bool finished = false;
int sortedCnt = 0;
int k;

void merge(vector<int>& arr, int p, int q, int r) {
    if (finished) return;

    vector<int> tmp;
    tmp.reserve(r - p + 1);

    int i = p, j = q + 1;

    while (i <= q && j <= r) {
        if (arr[i] <= arr[j]) tmp.push_back(arr[i++]);
        else tmp.push_back(arr[j++]);
    }

    while (i <= q) tmp.push_back(arr[i++]);
    while (j <= r) tmp.push_back(arr[j++]);

    for (int t = 0; t < (int)tmp.size(); t++) {
        arr[p + t] = tmp[t];

        if (!finished && ++sortedCnt == k) {
            finished = true;
            for (int v : arr) cout << v << ' ';
            cout << '\n';
            return;
        }
    }
}

void mergeSort(vector<int>& arr, int p, int r) {
    if (p >= r || finished) return;

    int q = (p + r) / 2;
    mergeSort(arr, p, q);
    mergeSort(arr, q + 1, r);
    merge(arr, p, q, r);
}

int main() {
    FASTIO;

    int n; cin >> n >> k;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    mergeSort(arr, 0, n - 1);

    if (!finished) cout << -1 << '\n';

    return 0;
}