//11575

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

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	while (n--) {
		int a, b;
		cin >> a >> b;
		string s;
		cin >> s;
		
		for (int i = 0; i < s.size(); i++) {
			cout << (char)((a * (s[i] - 'A') + b) % 26 + 'A');
		}
		cout << '\n';
	}

	return 0;
}