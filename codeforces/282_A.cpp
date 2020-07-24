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

	int t, ans = 0;
	cin >> t;
	while (t--) {
		string str;
		cin >> str;
		if (!str.compare("++X") || !str.compare("X++")) ans++;
		else ans--;
	}

	cout << ans;

	return 0;
}