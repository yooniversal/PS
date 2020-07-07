//2693

#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <vector>
#include <deque>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int t;
	int arr[10];

	cin >> t;
	while (t--) {
		for (int i = 0; i < 10; i++)
			cin >> arr[i];

		sort(arr, arr + 10);

		cout << arr[7]<<'\n';
	}

	return 0;
}