#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int, int> ii;

int n, m;
int a[51][51];

int max_size() {
    for(int r=min(n, m); r>1; --r) {
        for(int i=0; i+r-1<n; ++i) {
            for(int j=0; j+r-1<m; ++j) {
                int v = a[i][j], v2 = a[i][j+r-1], v3 = a[i+r-1][j], v4 = a[i+r-1][j+r-1];
                if(v != v2 || v != v3 || v != v4) continue;
                return r * r;
            }
        }
    }
    return 1;
}

int main () {

    cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

    cin >> n >> m;
    for(int i=0; i<n; ++i) {
        string s; cin >> s;
        for(int j=0; j<m; ++j) {
            a[i][j] = s[j] - '0';
        }
    }

    cout << max_size() << '\n';

    return 0;
}