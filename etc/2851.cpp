//2851

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

	int arr[10], sum, maxx=-1;
	
	for (int i = 0; i < 10; i++)
		cin >> arr[i];

	sum = 0;
		for (int j = 0; j < 10; j++) {
			sum += arr[j];
			if (abs(100-maxx) > abs(100-sum)) maxx = sum;
			else if (abs(100-maxx) == abs(100-sum))
				if (maxx < sum) maxx = sum;
		}

	cout << maxx;

	return 0;
}