//3047

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

	int tmp, order[3];
	string str;
	vector<int> arr;

	for (int i = 0; i < 3; i++) {
		cin >> tmp;
		arr.push_back(tmp);
	}

	sort(arr.begin(), arr.end());

	cin >> str;
	for (int i = 0; i < 3; i++) {
		order[i] = str[i] - 'A';
	}

	for(int i = 0; i < 3; i++) {
		cout << arr[order[i]] << " ";
	}
	return 0;
}