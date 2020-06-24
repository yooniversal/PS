//2160

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

	int n;
	long long ans = 0, tmp;
	vector<long long> arr;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		arr.push_back(tmp);
	}
	
	sort(arr.begin(), arr.end());

	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
			ans += arr[j] - arr[i];

	cout << 2*ans;

	return 0;
}