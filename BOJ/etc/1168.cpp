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

		//����
		//iterator�� ���� �������� �ʾƵ� ��� ����
		//vector�� Ư�� ���� ���� ����
		node.erase(node.begin() + m);

		m += (move - 1);
		
		//��� ���� 1�� �پ����Ƿ� --������ �ٿ��ֱ�
		//ȯ������ ���� O(N^2)
		//��ⷯ �������� ���� ȿ�� ����
		if (--mem > 0)
			m = m % mem;
	}

	return 0;
}