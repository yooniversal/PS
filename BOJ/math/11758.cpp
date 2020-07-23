//11758

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

int CCW(int x1, int y1, int x2, int y2, int x3, int y3) {
	int ans = x2 * y3 - x2 * y1 - x1 * y3 - x3 * y2 + x1 * y2 + x3 * y1;
	if (ans > 0) return 1;
	else if (ans == 0) return 0;
	else return -1;
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int x1, x2, x3, y1, y2, y3;
	cin >> x1 >> y1;
	cin >> x2 >> y2;
	cin >> x3 >> y3;
	
	cout << CCW(x1, y1, x2, y2, x3, y3);

	return 0;
}