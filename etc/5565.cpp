//5565

#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int	sum = 0;
	int total, temp;

	cin >> total;
	for (int i = 0; i < 9; i++) {
		cin >> temp;
		sum += temp;
	}

	cout << total - sum;

	return 0;
}