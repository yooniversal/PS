#include <bits/stdc++.h>

using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ii> vii;

int cnt[10];

int main() {
    FASTIO;

    int n;
    cin >> n;

    vector<int> a(n);
    for (int i=0; i<n; i++) cin >> a[i];

    int kind = 0, left = 0;
    int ret = 0;

    for (int right=0; right<n; right++) {
        if (cnt[a[right]] == 0) kind++;
        cnt[a[right]]++;

        while (kind > 2) {
            cnt[a[left]]--;
            if (cnt[a[left]] == 0) kind--;
            left++;
        }

        ret = max(ret, right - left + 1);
    }

    cout << ret << "\n";

    return 0;
}