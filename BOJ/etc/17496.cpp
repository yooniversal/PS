//17496

#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <deque>
#include <cmath>
#include <ctime>
#include <algorithm>
using namespace std;

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, t, c, p;
	cin >> n >> t >> c >> p;

	cout << ((n - 1) / t) * c * p;

	return 0;
}