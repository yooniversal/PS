//1934

#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <deque>
#include <cmath>
#include <ctime>
#include <algorithm>
using namespace std;

int GCD(int a, int b) {
	int temp;
	
	while (b != 0) {
		temp = a % b;
		a = b;
		b = temp;
	}
	return a;
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int t, a, b;

	cin >> t;

	while (t--) {
		cin >> a >> b;
		cout << GCD(a, b) * a / GCD(a, b) * b / GCD(a, b) << "\n";
	}

	return 0;
}