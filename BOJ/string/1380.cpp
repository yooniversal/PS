#include <bits/stdc++.h>

using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ii> vii;

int main() {
    FASTIO;

    int stageCnt = 1;
    while (true) {
        int n; cin >> n;
        if (n == 0) break;
        cin.ignore();

        vector<string> a;
        for (int i=0; i<n; i++) {
            string s; getline(cin, s);
            a.push_back(s);
        }

        vi cnt(n+1, 0);
        for (int i=0; i<2*n-1; i++) {
            int number; char c; cin >> number >> c;
            number--;
            cnt[number]++;
        }

        for (int i=0; i<n; i++) {
            if (cnt[i] == 1) {
                cout << stageCnt++ << " " << a[i] << '\n';
                break;
            }
        }
    }

    return 0;
}