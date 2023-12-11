#include <iostream>
#include <string>
#include <cstring>
#include <map>
#include <algorithm>
using namespace std;

int main() {

    cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

    int t; cin >> t;
    while (t--) {
        string s; cin >> s;
        cout << s[0] << s[s.size()-1] << '\n';
    }

    return 0;
}