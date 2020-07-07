//14888

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, num[11], oper[10], temp, line[10], idx;
vector<int> list, v;

//ver�� ���� ������ �������ִ� �Լ�
int operat(int a, int b, int ver) {
	if (ver == 0)
		return a + b;
	else if (ver == 1)
		return a - b;
	else if (ver == 2)
		return a * b;
	else
		return a / b;
}

void process() {
	for (int i = 0; i < n - 1; i++)
		if (i == 0)											//ó���� temp �ʱ�ȭ�� ���� i==0 ���� ����
			if (i == n - 2) {								//ó���� ������ ���
				temp = operat(num[i], num[i + 1], line[i]);	
				list.push_back(temp);						//�������� list�� ���� �߰�
			}
			else
				temp = operat(num[i], num[i + 1], line[i]);
		else if (i == n - 2) {
			temp = operat(temp, num[i + 1], line[i]);
			list.push_back(temp);							//�������� list�� ���� �߰�
		}
		else
			temp = operat(temp, num[i + 1], line[i]);
}

void listcase() {

	//permutation �Լ��� ���� v ������ �����ְ�
	do {
		//���� v ������ line�� �������ش�
		for (int i = 0; i < v.size(); i++)
			line[i] = v[i];

		//���!
		process();

	} while (next_permutation(v.begin(), v.end()));
}

int getMax() {
	int max = list[0];
	for (int i = 0; i < list.size(); i++)
		if (max < list[i])
			max = list[i];

	return max;
}

int getMin() {
	int min = list[0];
	for (int i = 0; i < list.size(); i++)
		if (min > list[i])
			min = list[i];

	return min;
}

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> num[i];

	// + - * /
	//�Է¹޴� 4���� operator ���� �ε����� ������ vector v�� ����
	for (int i = 0; i < 4; i++) {
		cin >> oper[i];
		while(oper[i] != 0) {
			v.push_back(i);
			oper[i]--;
		}
	}

	listcase();

	cout << getMax() << "\n";
	cout << getMin();

	return 0;
}