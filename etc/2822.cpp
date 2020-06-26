//2822

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

	int arr[8], sum = 0, tmp[8], m1, m2, m3;
	for (int i = 0; i < 8; i++) {
		cin >> arr[i];
		tmp[i] = arr[i];
	}

	sort(tmp, tmp + 8);

	for (int i = 0; i < 8; i++) {
		if (arr[i] == tmp[0]) m1 = i;
		else if (arr[i] == tmp[1]) m2 = i;
		else if (arr[i] == tmp[2]) m3 = i;

		if (i > 2) sum += tmp[i];
	}

	cout << sum<<'\n';
	for (int i = 0; i < 8; i++) {
		if (i != m1 && i != m2 && i != m3)
			cout << i+1 << " ";
	}



	return 0;
}