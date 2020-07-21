//10173

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

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	string str;

	while (getline(cin, str)) {
		if (str == "EOI") break;
		bool key = false;
		int size = 0, cnt[4];
		memset(cnt, 0, sizeof(cnt));
		for (int i = 0; i < str.size(); i++) {
			if (key) break;
			if (str[i] == ' ') {
				size = 0;
				memset(cnt, 0, sizeof(cnt));
			}
			else {
				size++;
				if (str[i] == 'N' || str[i] == 'n') cnt[0] = 1;
				if (str[i] == 'E' || str[i] == 'e')
					if (cnt[0]) cnt[1] = 1;
				if (str[i] == 'M' || str[i] == 'm')
					if (cnt[1]) cnt[2] = 1;
				if (str[i] == 'O' || str[i] == 'o')
					if (cnt[2]) {
						cnt[3] = 1;
						if(size==4 && (str[i+1] == ' ' || str[i+1] == ',' || str.size() == i+1)) key = true;
					}
			}
		}
		if (!key) cout << "Missing" << '\n';
		else cout << "Found" << '\n';
	}

	return 0;
}