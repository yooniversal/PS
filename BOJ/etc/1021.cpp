//1021

#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <deque>
#include <list>
#include <algorithm>
using namespace std;

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	deque<int> node;
	int n, m, target, ans=0, cur, temp;

	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		node.push_back(i);

	while (m--) {
		cin >> target;
		
		//target값을 갖는 인덱스 얻기
		for (int i = 0; i < node.size(); i++)
			if (node[i] == target) {
				cur = i;
				break;
			}

		int left = cur;
		int right = node.size() - cur;

		if (left < right) {
			for (int i = 0; i < left; i++) {
				temp = node.front();
				node.pop_front();
				node.push_back(temp);
				ans++;
			}
			node.pop_front();	//target 삭제
		}
		else {
			for (int i = 0; i < right; i++) {
				temp = node.back();
				node.pop_back();
				node.push_front(temp);
				ans++;
			}
			node.pop_front();	//target 삭제
		}


	}

	cout << ans;

	return 0;
}