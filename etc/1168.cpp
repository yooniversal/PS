//1168

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

	vector<int> node;

	int n, move, m, mem;

	cin >> n >> move;
	m = move - 1;
	mem = n;

	for (int i = 1; i <= n; i++) {
		node.push_back(i);
	}

	cout << "<";
	for (int i = 0; i < n; i++) {

		cout << node[m];

		if (i == n - 1) {
			cout << ">";
			return 0;
		}
		else
			cout << ", ";

		//삭제
		//iterator는 따로 선언하지 않아도 사용 가능
		//vector도 특정 원소 삭제 가능
		node.erase(node.begin() + m);

		m += (move - 1);
		
		//사람 수가 1명 줄었으므로 --연산자 붙여주기
		//환형으로 돌면 O(N^2)
		//모듈러 연산으로 같은 효과 가능
		if (--mem > 0)
			m = m % mem;
	}

	return 0;
}