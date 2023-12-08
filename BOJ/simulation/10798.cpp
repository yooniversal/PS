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

    vector<string> a;
    int max_len = 0;
    for (int i=0; i<5; i++) {
        string s; cin >> s;
        a.push_back(s);
        max_len = max(max_len, (int)s.size());
    }

    for (int i=0; i<max_len; i++) {
        for (int j=0; j<5; j++) {
            if (a[j].size() <= i) continue;
            cout << a[j][i];
        }
    }
    cout << '\n';

    return 0;
}