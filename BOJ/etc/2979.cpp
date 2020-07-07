//2979

#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <vector>
#include <deque>
#include <cmath>
#include <algorithm>
using namespace std;

int t[101];
int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int A, B, C;
	
	cin >> A >> B >> C;
	B *= 2; C *= 3;

	for (int i = 0; i < 3; i++) {
		int tmp1, tmp2;
		cin >> tmp1 >> tmp2;

		for (int j = tmp1; j < tmp2; j++)
			t[j]++;
	}

	int sum = 0;
	for (int i = 0; i < 101; i++) {
		if (t[i] == 1) sum += A;
		else if (t[i] == 2) sum += B;
		else if (t[i] == 3) sum += C;
	}

	cout << sum;

	return 0;
}