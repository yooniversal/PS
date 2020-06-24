//1697

#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <vector>
#include <deque>
#include <cmath>
#include <algorithm>
using namespace std;

int X, Y;
bool chk[200001];
int ans[200001];
deque<int> que;

void bfs(int start) {
	//start 값 삽입
	int cur;
	que.push_back(start);
	while (!que.empty()) {
		//순차적으로 밖의 값부터 빼주고
		cur = que.back();
		que.pop_back();
		chk[cur] = true;

		//종료 조건
		if (chk[Y] == true) {
			cout << ans[Y];
			return;
		}

		//빼준 값을 정해진 매커니즘으로 진행
		if (cur-1 >= 0 && chk[cur - 1] == false) {
			chk[cur - 1] = true;
			que.push_front(cur - 1);
			ans[cur - 1] = ans[cur] + 1;
		}
		if (cur + 1 <= 100000 && chk[cur + 1] == false) {
			chk[cur + 1] = true;
			que.push_front(cur + 1);
			ans[cur + 1] = ans[cur] + 1;
		}
		if (2 * cur <= 100000 && chk[2 * cur] == false) {
			chk[2 * cur] = true;
			que.push_front(2 * cur);
			ans[2 * cur] = ans[cur] + 1;
		}
	}
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	cin >> X >> Y;

	bfs(X);

	return 0;
}