//17386

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

struct dd {
	ll x, y;
};

bool CCW(dd a, dd b, dd c) {
	ll tmp = a.x * b.y + b.x * c.y + c.x * a.y;
	tmp -= a.y * b.x + b.y * c.x + c.y * a.x;
	if (tmp > 0) return true;
	else return false;
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	dd xy[4];
	
	//input
	for (int i = 0; i < 4; i++)
		cin >> xy[i].x >> xy[i].y;

	if((CCW(xy[0], xy[1], xy[2]) != CCW(xy[0], xy[1], xy[3])) && (CCW(xy[1], xy[0], xy[2]) != CCW(xy[1], xy[0], xy[3])))
		if ((CCW(xy[2], xy[3], xy[0]) != CCW(xy[2], xy[3], xy[1])) && (CCW(xy[3], xy[2], xy[0]) != CCW(xy[3], xy[2], xy[1])))
			cout << "1";
		else cout << "0";
	else cout << "0";

	return 0;
}