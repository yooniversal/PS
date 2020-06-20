//1964

#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <deque>
#include <list>
#include <algorithm>
using namespace std;

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	long long int n;

	cin >> n;

	cout << ((3 * n * n + 5 * n + 2) / 2) % 45678;

	return 0;
}