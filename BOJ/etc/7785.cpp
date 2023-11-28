#include <iostream>
#include <string>
#include <cstring>
#include <map>
#include <algorithm>
using namespace std;

map<string, bool> chk;

int main() {

    cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

    int n; cin >> n;
    vector<string> a;
    for (int i=0; i<n; i++) {
        string s, t; cin >> s >> t;
        if (t == "enter") {
            a.push_back(s);
            chk[s] = true;
        } else {
            chk[s] = false;
        }
    }

    vector<string> ans;
    for (auto& str : a) {
        if (chk[str]) {
            ans.push_back(str);
        }
    }

    sort(ans.rbegin(), ans.rend());

    map<string, bool> printed;
    for (auto& str : ans) {
        if (printed[str]) continue;
        printed[str] = true;
        cout << str << '\n';
    }

    return 0;
}