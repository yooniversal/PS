//3745

#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <vector>
#include <deque>
#include <stack>
#include <queue>
#include <cmath>
#include <algorithm>
#include <functional>
using namespace std;

typedef long long ll;
ll arr[1000001];

//lower_bound function : O(logn)
int searchindex(ll key, int start, int end) {
	int mid = (start + end) / 2;

	if (arr[mid + 1] == NULL) return mid;

	while (start < end) {
		mid = (start + end) / 2;
		if (arr[mid - 1] < key && key <= arr[mid]) return mid;
		else if (key <= arr[mid]) end = mid;
		else start = mid + 1;
	}
	return end;
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	//ios_base::sync_with_stdio(false);

	ll tempvalue;
	int cnt = 0, n, idx;

	while (scanf("%d", &n) > 0) {
		for (int i = 1; i <= n; i++) {
			cin >> tempvalue;
			if (arr[cnt] < tempvalue) {
				arr[++cnt] = tempvalue;
			}
			else {
				idx = searchindex(tempvalue, 1, cnt);
				arr[idx] = tempvalue;
			}
		}
		cout << cnt << '\n';
		cnt = 0;
	}

	return 0;
}