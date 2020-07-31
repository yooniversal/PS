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

	int n, m; cin >> n >> m;
	vector<int> arr(m);
	for (int i = 0; i < m; i++) {
		cin >> arr[i];
	}

	sort(arr.begin(), arr.end());

	vector<int> ans;
	for (int i = 0; i < m-n+1; i++) {
		ans.push_back(arr[n - 1 + i] - arr[i]);
	}

	int min = ans[0];
	for (auto& a : ans) {
		if (min > a) min = a;
	}
	
	cout << min;

	return 0;
}