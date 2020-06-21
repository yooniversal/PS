//9295

#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <deque>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int t, a, b, cnt=0;

	cin >> t;
	while (t--) {
		cin >> a >> b;

		cout << "Case " << cnt + 1 << ": " << a + b << "\n";
		cnt++;
	}

	return 0;
}