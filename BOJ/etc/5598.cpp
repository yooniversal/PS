//5598

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
	cin >> str;
	for (int i = 0; i < str.size(); i++) {
		if ('D' <= str[i] && str[i] <= 'Z') str[i] -= 3;
		else if (str[i] == 'A') str[i] = 'X';
		else if (str[i] == 'B') str[i] = 'Y';
		else if (str[i] == 'C') str[i] = 'Z';
	}

	cout << str;

	return 0;
}