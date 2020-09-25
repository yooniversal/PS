//7662
#include <bits/stdc++.h>
using namespace std;
#define INF 1000000001
#define MAX 100001
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

multiset<int> s;

int main() {

    cin.tie(nullptr);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int t; cin >> t;
    while (t--) {
        s.clear();

        int q; cin >> q;
        while (q--) {
            char oper; cin >> oper;
            string str; cin >> str;
            if (oper == 'I') {
                int n = 0;
                if (str[0] != '-') {
                    for (int j = 0; j < str.size(); ++j)
                        n = n * 10 + (str[j] - '0');
                    s.insert(n);
                }
                else {
                    for (int j = 1; j < str.size(); ++j)
                        n = n * 10 + (str[j] - '0');
                    s.insert(n * (-1));
                }
            }
            else {
                if (s.empty()) continue;
                if (str[0] == '1') {
                    set<int>::iterator it = s.end();
                    s.erase(--it);
                }
                else {
                    set<int>::iterator it = s.begin();
                    s.erase(it);
                }
            }
        }

        if (!s.empty()) {
            set<int>::iterator maxx = s.end();
            set<int>::iterator minn = s.begin();
            --maxx;
            cout << *maxx << " " << *minn << '\n';
        }
        else
            cout << "EMPTY\n";
    }

    return 0;
}