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

	int n; cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	int tmp = arr[0], ans = 1, answer=1;
	for (int i = 1; i < n; i++) {
		if (tmp <= arr[i]) {
			ans++;
			tmp = arr[i];
			//cout << "i:"<<i<<" ans:" << ans << '\n';
			answer = max(answer, ans);
		}
		else {
			tmp = arr[i];
			ans = 1;
		}
	}

	cout << answer;

	return 0;
}