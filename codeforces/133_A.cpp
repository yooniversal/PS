#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <cmath>
#include <algorithm>
#include <map>
using namespace std;

typedef long long ll;

bool compare(int a, int b) { return a > b; }

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	string s; cin >> s;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == 'H' || s[i] == 'Q' || s[i] == '9') {
			cout << "YES"; return 0;
		}
	}
	
	cout << "NO";

	return 0;
}