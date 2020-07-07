//2965

#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <deque>
#include <list>
#include <algorithm>
using namespace std;

int a, b, c, cnt, ans;

void dfs() {

	//종료 조건
	if (c-a == 2) {
		if (ans < cnt)
			ans = cnt;
		return;
	}

	if (b - a > c - b) {
		int temp = b;
		b = a + 1;
		c = temp;
		cnt++;
	}
	else {
		int temp = b;
		b = c - 1;
		a = temp;
		cnt++;
	}

	dfs();
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> a >> b >> c;

	dfs();

	cout << ans;

	return 0;
}