//9251

#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <vector>
#include <deque>
#include <cmath>
#include <algorithm>
using namespace std;

int ans;
int check[1001][1001];

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int po1 = 0, po2 = 0, cnt = 0;
	string str1, str2;

	cin >> str1 >> str2;

	for (int i = 0; i < str1.size(); i++)
		for (int j = 0; j < str2.size(); j++)
			if (str1[i] == str2[j])
				check[i + 1][j + 1] = check[i][j] + 1;
			else
				check[i + 1][j + 1] = max(check[i][j + 1], check[i + 1][j]);

	cout << check[str1.size()][str2.size()];

	return 0;
}