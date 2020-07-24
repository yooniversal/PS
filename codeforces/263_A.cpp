#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <cmath>
#include <algorithm>
#include <map>
using namespace std;

typedef long long ll;

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int a[5][5], key;

	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++) {
			cin >> a[i][j];
			if (a[i][j] == 1) {
				key = abs(i - 2) + abs(j - 2);
			}
		}

	cout << key;

	return 0;
}