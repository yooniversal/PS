//2010

#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	int n, ans=0, input;

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> input;
		if (i == n - 1)
			ans += input;
		else
			ans += input - 1;
	}

	cout << ans;
			


	return 0;
}