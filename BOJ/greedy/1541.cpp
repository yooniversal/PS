//1541

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	string str;
	int temp=0, ans = 0;
	bool opch = false;

	cin >> str;

	for (int i = 0; i < str.length(); i++) {
		//-�� �ɸ��� ���� ��
		if (opch == false) {
			if (str[i] == '+') {		//��� +�� ������ ��Ȳ�̹Ƿ� ��� �����ش�
				ans += temp;
				temp = 0;
			}
			else if (str[i] == '-') {
				opch = true;			//-�� ������ �� ����� ���̹Ƿ� ��带 �ٲ��ش�
				ans += temp;			//�ϴ� �տ������� +�̹Ƿ� �����ش�
				temp = 0;
			}
			else {
				temp = temp * 10 + (str[i] - '0');	
				if (i == str.length() - 1)
					ans += temp;
			}
		}
		//-�� �ɸ� ��
		else if(opch == true) {
			if (str[i] == '+') {
				ans -= temp;
				temp = 0;
			}
			else if (str[i] == '-') {	//-�� �ּ� �� �� ���� �̻� �� �������� �ȴ�
				ans -= temp;			//���� -�� ���͵� ��带 �ٲ����� �ʴ´�
				temp = 0;
			}
			else {
				temp = temp * 10 + (str[i] - '0');
				if (i == str.length() - 1)
					ans -= temp;
			}
		}
	}

	cout << ans;

	return 0;
}