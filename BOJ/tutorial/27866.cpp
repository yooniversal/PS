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

    string s; cin >> s;
    int i; cin >> i;
    cout << s[i-1] << '\n';

    return 0;
}