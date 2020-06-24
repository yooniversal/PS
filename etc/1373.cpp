//1373

#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <vector>
#include <deque>
#include <cmath>
#include <algorithm>
using namespace std;

char str[1000001];

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> str;
	int strl = 0, cn=0;
	while (1) {
		if (str[cn] != NULL) cn++;
		else {
			strl = cn;
			break;
		}
	}
	int lon = strl % 3;
	int point, cnt = 0, tmp=0;

	if (lon == 1)
		cout << str[0];
	else if (lon == 2) {
		cout << (str[0] - '0') * 2 + (str[1] - '0');
	}
	else if(lon == 0){
		cout << (str[0] - '0')*4 + (str[1] - '0') * 2 + (str[2] - '0');
	}

	if (lon != 0)
		point = lon;
	else
		point = 3;

	while (strl > 3) {

		if (cnt == 3) {
			cout << tmp;
			cnt = 0;
			tmp = 0;
			if (point == strl) break;
		}
		if(cnt == 0)
			tmp += (str[point] - '0') * 4;
		if (cnt == 1)
			tmp += (str[point] - '0') * 2;
		if (cnt == 2)
			tmp += str[point] - '0';

		cnt++;
		point++;
	}

	return 0;
}