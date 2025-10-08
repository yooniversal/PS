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

bool hasNext(string& saved, char target) {
    sort(saved.begin(), saved.end());
    return target < saved[saved.size()-1];
}

int main() {
    FASTIO;

    int t; cin >> t;
    while (t--) {
        string s; cin >> s;
        string saved = "";
        
        for (int i=s.size()-1; i>=0; i--) {
            if (i == s.size()-1) {
                saved += s[i];
            } else {
                if (hasNext(saved, s[i])) {
                    char tmp = s[i];

                    for (int j=0; j<saved.size(); j++) {
                        if (s[i] < saved[j]) {
                            s[i] = saved[j];
                            saved.erase(j, 1);
                            break;
                        }
                    }
                    
                    saved += tmp;
                    sort(saved.begin(), saved.end());
                    
                    for (int j=i+1, k=0; j<s.size(); j++, k++) {
                        s[j] = saved[k];
                    }

                    break;
                } else {
                    saved += s[i];
                }
            }
        }

        cout << s << '\n';
    }

    return 0;
}