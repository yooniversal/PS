//10474

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

	int a, b;

	while(1){
		cin >> a >> b;
		if (a == 0 && b == 0) return 0;

		cout << a / b << " " << a % b << " / " << b<<'\n';
	}

	return 0;
}