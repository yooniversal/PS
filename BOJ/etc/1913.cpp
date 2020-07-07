//1913

#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <deque>
#include <cmath>
#include <algorithm>
using namespace std;

int mi[999][999], key, dx, dy;

void map(int n) {
	int flag = n * n, y, x, mode = 0;
	
	mi[0][0] = flag; y = 0; x = 0;
	flag--;
	while (flag != 0) {
		if (mi[y][x] == key) {
			dy = y; dx = x;
		}
		if (mode==0) {
			mi[y + 1][x] = flag;
			flag--;
			y++;
			if (y == n-1) mode = 1;
			else if( mi[y + 1][x] != 0) mode = 1;
			continue;
		}
		if (mode == 1) {
			mi[y][x + 1] = flag;
			flag--;
			x++;
			if (x == n-1) mode = 2;
			else if( mi[y][x + 1] != 0) mode = 2;
			continue;
		}
		if (mode == 2) {
			mi[y - 1][x] = flag;
			flag--;
			y--;
			if (y == 0) mode = 3;
			else if( mi[y - 1][x] != 0) mode = 3;
			continue;
		}
		if (mode == 3) {
			mi[y][x - 1] = flag;
			flag--;
			x--;
			if (x == 0) mode = 0;
			else if( mi[y][x - 1] != 0) mode = 0;
			continue;
		}
	}
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n >> key;

	map(n);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cout << mi[i][j] << " ";
		cout << endl;
	}
	
	cout << dy + 1 << " " << dx + 1;

	return 0;
}