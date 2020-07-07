//4999

#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <vector>
#include <deque>
#include <queue>
#include <cmath>
#include <algorithm>
#include <functional>
using namespace std;

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	string str1, str2;
	int cnt1 = 0, cnt2 = 0;

	cin >> str1 >> str2;

	for (int i = 0; i < str1.size(); i++)
		if (str1[i] == 'a') cnt1++;

	for (int i = 0; i < str2.size(); i++)
		if (str2[i] == 'a') cnt2++;

	if (cnt1 < cnt2) cout << "no";
	else cout << "go";

	return 0;
}