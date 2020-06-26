//1629

#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

//divide and conquer
//°ö¼À ¾ÆÀÌµð¾î
long long dc(long long a, long long b, long long c) {
	long long t;

	if (b == 1) return a;
	else {
		t = dc(a, b / 2, c);
		if (b % 2 == 1) return ((t*t)%c*a)%c;
		else return (t*t)% c;
	}
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	long long a, b, c;

	cin >> a >> b >> c;

	cout << dc(a%c, b, c) % c;

	return 0;
}