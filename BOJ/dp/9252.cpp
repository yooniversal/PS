//9252

#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <vector>
#include <deque>
#include <queue>
#include <cmath>
#include <algorithm>
using namespace std;

int ans;
int check[1001][1001];

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int po = 0, row = 0, cnt = 1;
	deque<int> idx;
	string str1, str2, tmp;

	cin >> str1 >> str2;
	if (str1.size() > str2.size()) {
		tmp = str1;
		str1 = str2;
		str2 = tmp;
	}

	for (int i = 0; i < str2.size(); i++)
		for (int j = 0; j < str1.size(); j++) {
			if (str2[i] == str1[j])
				check[i + 1][j + 1] = check[i][j] + 1;
			else
				check[i + 1][j + 1] = max(check[i][j + 1], check[i + 1][j]);
			if (po < check[i + 1][j + 1]) {
				po = check[i + 1][j + 1];
				row = i + 1;
			}
		}

	cout << check[str2.size()][str1.size()] << '\n';

	int y = str2.size();
	int x = str1.size();

	while (y != 0 && x != 0) {
		if (check[y][x] == check[y][x - 1]) x--;
		else if (check[y][x] == check[y - 1][x]) y--;
		else {
			idx.push_front(x - 1);
			y--; x--;
		}
	}

	while (!idx.empty()) {
		cout << str1[idx.front()];
		idx.pop_front();
	}

	return 0;
}