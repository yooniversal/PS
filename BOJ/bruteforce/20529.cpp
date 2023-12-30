#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <map>
#include <stack>
#include <algorithm>
#include <cmath>
using namespace std;

typedef long long ll;

const int INF = 987654321;

int diff(string& s1, string &s2) {
    int ret = 0;
    for (int i=0; i<s1.size(); i++) {
        if (s1[i] != s2[i]) ret++;
    }
    return ret;
}

int f(string& s1, string& s2, string& s3) {
    return diff(s1, s2) + diff(s2, s3) + diff(s1, s3);
}

int main() {

    cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        map<string, int> chk;
        vector<string> a;
        for (int i=0; i<n; i++) {
            string s; cin >> s;
            if (chk[s] >= 3) continue;
            chk[s]++;
            a.push_back(s);
        }

        int ret = INF;
        for (int i=0; i<a.size(); i++) {
            for (int j=i+1; j<a.size(); j++) {
                for (int k=j+1; k<a.size(); k++) {
                    ret = min(ret, f(a[i], a[j], a[k]));
                }
            }
        }

        if (ret != INF) cout << ret << '\n';
        else cout << 0 << '\n';
    }

    return 0;
}