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
    for (int i=0; i<n/4; i++) {
        cout << "long ";
    }
    cout << "int" << '\n';

    return 0;
}