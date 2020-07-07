//2669

#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <vector>
#include <deque>
#include <cmath>
#include <algorithm>
using namespace std;

int check[102][102];

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int cnt=0, block = 4;
	int sy, sx, ey, ex;

	while (block--) {
		cin >> sx >> sy >> ex >> ey;
		for (int y = sy; y < ey; y++)
			for (int x = sx; x < ex; x++) {
				check[y][x] = 1;
			}
	}

	for (int i = 0; i <= 100; i++) {
		for (int j = 0; j <= 100; j++) {
			if (check[i][j] == 1)
				cnt++;
		}
	}

	cout << cnt;

	return 0;
}