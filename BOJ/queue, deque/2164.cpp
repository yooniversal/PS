//2920

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

	int n, temp;
	deque<int> arr;
	cin >> n;

	for (int i = 1; i <= n; i++)
		arr.push_back(i);

	while (arr.size() != 1) {
		arr.pop_front();
		temp = arr.front();
		arr.pop_front();
		arr.push_back(temp);
	}

	cout << arr.front();

	return 0;
}