//13913

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
pair<bool, deque<int>> chk[200001];
int ans[200001];
deque<int> que, result;

void prt(int n) {
	int tmp = chk[n].second.front();
	result.push_front(tmp);
	chk[n].second.pop_front();
	if(!chk[tmp].second.empty())
		prt(tmp);
}

void bfs(int start) {
	//start 값 삽입
	int cur;
	que.push_back(start);
	while (!que.empty()) {
		//순차적으로 밖의 값부터 빼주고
		cur = que.back();
		que.pop_back();
		chk[cur].first = true;

		//종료 조건
		if (chk[Y].first == true) {
			cout << ans[Y] << '\n';
			if(!chk[Y].second.empty())
				prt(Y);
			while (!result.empty()) {
				cout << result.front() << " ";
				result.pop_front();
			}
			cout << Y;
			return;
		}

		//빼준 값을 정해진 매커니즘으로 진행
		if (cur - 1 >= 0 && chk[cur - 1].first == false) {
			chk[cur - 1].first = true;
			chk[cur - 1].second.push_back(cur);
			que.push_front(cur - 1);
			ans[cur - 1] = ans[cur] + 1;
		}
		if (cur + 1 <= 100000 && chk[cur + 1].first == false) {
			chk[cur + 1].first = true;
			chk[cur + 1].second.push_back(cur);
			que.push_front(cur + 1);
			ans[cur + 1] = ans[cur] + 1;
		}
		if (2 * cur <= 100000 && chk[2 * cur].first == false) {
			chk[2 * cur].first = true;
			chk[2*cur].second.push_back(cur);
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