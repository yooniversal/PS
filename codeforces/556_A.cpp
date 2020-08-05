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

	int n; cin >> n;
	string s;
	cin >> s;

	int a = 0, b = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '0') a++;
		else b++;
	}

	cout << abs(a - b);

	return 0;
}