//5582

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
int d[4001][4001];

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	string str1, str2, tmp;

	cin >> str1 >> str2;
	//긴건 str1, 짧은건 str2
	if (str1.size() < str2.size()) {
		tmp = str1;
		str1 = str2;
		str2 = tmp;
	}

	for (int i = 1; i <= str1.size(); i++) {
		for (int j = 1; j <= str2.size(); j++) {
			//str1[0~i-2], str2[0~j-2] 값 + 1
			if (str1[i - 1] == str2[j - 1]) d[i][j] = d[i - 1][j - 1] + 1;
			//조건 만족하지 않으면 이후 값은 의미없음
			else d[i][j] = 0;
			ans = max(ans, d[i][j]);
		}
	}

	cout << ans;

	return 0;
}