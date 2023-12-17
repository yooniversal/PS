#include <iostream>
#include <string>
#include <cstring>
#include <map>
#include <stack>
#include <algorithm>
#include <cmath>
using namespace std;

typedef long long ll;

const int INF = 987654321;

int n;
bool is_friend[55][55];

int main() {

    cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

    cin >> n;
    for (int i=0; i<n; i++) {
        string s; cin >> s;
        for (int j=0; j<s.size(); j++) {
            if (s[j] == 'Y') {
                is_friend[i][j] = true;
            }
        }
    }

    int max_cnt = 0;

    for (int i=0; i<n; i++) {
        int cnt = 0;
        for (int j=0; j<n; j++) {
            if (i == j) continue;
            if (is_friend[i][j]) {
                cnt++;
                continue;
            }

            for (int k=0; k<n; k++) {
                if (k == i || k == j) continue;
                if (is_friend[k][i] && is_friend[k][j]) {
                    cnt++;
                    break;
                }
            }
        }
        
        if (max_cnt < cnt) {
            max_cnt = cnt;
        }
    }

    cout << max_cnt << '\n';

    return 0;
}