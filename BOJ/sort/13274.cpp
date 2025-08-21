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

typedef long long ll;

const int INF = 987654321;
const int MOD = 1000000007;

void FASTIO() {
    cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
}

void query(vector<ll>& arr, int l, int r, ll x) {
    vector<ll> origin, temp;

    for (int i=0; i<arr.size(); i++) {
        if (l <= i && i <= r) temp.push_back(arr[i] + x);
        else origin.push_back(arr[i]);
    }

    int i=0, j=0, k=0;
    while (i < origin.size() && j < temp.size()) {
        if (origin[i] <= temp[j]) arr[k++] = origin[i++];
        else arr[k++] = temp[j++];
    }

    while (i < origin.size()) arr[k++] = origin[i++];
    while (j < temp.size()) arr[k++] = temp[j++];
}

int main() {
    FASTIO();

    int n, k; cin >> n >> k;
    vector<ll> arr;
    
    for (int i=0; i<n; i++) {
        ll v; cin >> v;
        arr.push_back(v);
    }
    sort(arr.begin(), arr.end());

    while (k--) {
        int l, r; ll x; cin >> l >> r >> x;
        query(arr, l-1, r-1, x);
    }

    for (auto& v : arr) {
            cout << v << " ";
        }
        cout << '\n';

    return 0;
}