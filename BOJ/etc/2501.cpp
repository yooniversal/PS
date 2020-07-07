//2501

#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <deque>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, k;
	vector<int> temp;
	cin >> n >> k;

	for (int i = 1; i <= n; i++)
		if (n % i == 0)
			temp.push_back(i);

	if (temp.size() >= k)
		cout << temp[k - 1];
	else
		cout << "0";

	return 0;
}