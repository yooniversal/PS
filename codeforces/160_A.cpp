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

bool compare(int a, int b) { return a > b; }

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n; cin >> n;
	vector<int> arr(n);
	int mysum = 0, twinsum = 0;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		twinsum += arr[i];
	}

	sort(arr.begin(), arr.end(), compare);

	for (int i = 0; i < n; i++) {
		twinsum -= arr[i];
		mysum += arr[i];
		if (mysum > twinsum) {
			cout << i + 1;
			return 0;
		}
	}
	

	return 0;
}