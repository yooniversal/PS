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

	int t, ans=0;
	cin >> t;
	while (t--) {
		int a, b, c, result=0;
		cin >> a >> b >> c;
		result = a + b + c;

		if (result >= 2) ans++;
	}
	cout << ans;

	return 0;
}