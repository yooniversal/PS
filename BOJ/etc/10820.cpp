//10820

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
		int l = 0, b = 0, n = 0, bl = 0;
		for (int i = 0; i < str.length(); i++) {
			if ('a' <= str[i] && str[i] <= 'z') l++;
			else if ('A' <= str[i] && str[i] <= 'Z') b++;
			else if ('0' <= str[i] && str[i] <= '9') n++;
			else if (str[i] == ' ') bl++;
		}
		cout << l << " " << b << " " << n << " " << bl << '\n';
	}
	

	return 0;
}