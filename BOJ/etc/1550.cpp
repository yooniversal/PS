//1550

#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <vector>
#include <deque>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	char str[6];
	cin >> str;

	int strl, cnt=0;
	while (1) {
		if (str[cnt] != NULL) cnt++;
		else {
			strl = cnt;
			break;
		}
	}

	long long ans = 0;
	for (int i = 0; i < strl; i++) {
		if ('0' <= str[i] && str[i] <= '9') ans = ans*16 + str[i] - '0';
		else ans = ans*16 + 10 + str[i] - 'A';
	}

	cout << ans;

	return 0;
}