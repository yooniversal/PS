//2744

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

	string str;
	cin >> str;

	for (int i = 0; i < str.size(); i++)
		if ('a' <= str[i] && str[i] <= 'z') cout << (char)(str[i] - ('a' - 'A'));
		else cout << (char)(str[i] + ('a' - 'A'));



	return 0;
}