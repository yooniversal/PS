#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int main() {
	
	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> arr(n);
		for (int i = 0; i < n; i++) cin >> arr[i];

		//숫자가 pivot을 기준으로 정렬이 돼있으면 된다
		int i;
		for (i = n - 1; i > 0; i--)
			if (arr[i - 1] < arr[i]) break;
		for (i; i > 0; i--)
			if (arr[i - 1] > arr[i]) break;
		cout << i << '\n';
	}

	return 0;
}