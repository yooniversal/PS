//2997

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

	int tmp;
	vector<int> arr;

	for (int i = 0; i < 3; i++) {
		cin >> tmp;
		arr.push_back(tmp);
	}

	sort(arr.begin(), arr.end());

	if (arr[1] - arr[0] == arr[2] - arr[1]) cout << arr[2] + (arr[1] - arr[0]);
	else if (arr[2] - arr[1] == 2 * (arr[1] - arr[0])) cout << arr[1] + (arr[1] - arr[0]);
	else if (2 * (arr[2] - arr[1]) == arr[1] - arr[0]) cout << arr[0] + (arr[2] - arr[1]);

	return 0;
}