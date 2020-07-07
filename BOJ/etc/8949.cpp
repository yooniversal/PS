//8949

#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <vector>
#include <deque>
#include <queue>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n1, n2, ans=0;
	cin >> n1 >> n2;

	vector<int> q;

	while (!(n1 == n2 && n1 == 0)) {
		int t1 = n1 % 10;
		int t2 = n2 % 10;

		q.push_back(t1 + t2);

		n1 /= 10; n2 /= 10;
	}

	for (int i = q.size() - 1; i >= 0; i--)
		cout << q[i];

	return 0;
}