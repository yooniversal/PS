#include <bits/stdc++.h>

using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ii> vii;

const int INF = 987654321;
const int MOD = 1000000007;

bool isPrefix(string& a, string& b) {
    if (a.size() > b.size()) return false;
    for (int i=0; i<a.size(); i++) {
        if (a[i] != b[i]) return false;
    }
    return true;
}

int main() {
    FASTIO;

    int n; cin >> n;
    vector<string> a(n);
    for (int i=0; i<n; i++) cin >> a[i];
    sort(a.begin(), a.end());

    int subsetSize = 0;
    for (int i=0; i<n; i++) {
        subsetSize++;
        for (int j=i+1; j<n; j++) {
            if (isPrefix(a[i], a[j])) i = j;
            else break;
        }
    }

    cout << subsetSize << '\n';

    return 0;
}