#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int, int> ii;

bool chk[20005];

int main() {

    cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

    int n, k; cin >> n >> k;
    string s; cin >> s;

    int ret = 0;
    for(int i=0; i<n; ++i) {
        if(s[i] == 'H') continue;
        for(int j=i-k; j<=i+k && j<n; ++j) {
            if(j<0 || i==j) continue;
            if(s[j] == 'P' || chk[j]) continue;
            chk[j] = true;
            ++ret;
            break;
        }
    }

    cout << ret << '\n';

    return 0;
}