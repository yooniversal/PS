//9375

#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int types, typearr[30], ans, temp=1;
vector<string> str;

bool isNew(string teststr) {
	for (int i = 0; i < types; i++)
		if (str[i] == teststr)
			return false;
	return true;
}

int getIdx(string teststr) {
	for (int i = 0; i < types; i++)
		if (str[i] == teststr)
			return i;
	return -1;	//error
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N, M;
	int T, all;
	string str1, str2;
	

	cin >> T;
	while (T--) {
		for (int i = 0; i < 30; i++)
			typearr[i] = 1;

		cin >> all;
		//�������� ���� �ľ��ϱ�
		for (int i = 0; i < all; i++) {
			cin >> str1 >> str2;
			//���ο� �����ΰ�?
			if (isNew(str2) == true) {
				str.push_back(str2);	//������ �߰�
				typearr[types]++;
				types++;				//���� ���� �ø���
			}
			//�̹� �ִ� �������
			else {
				typearr[getIdx(str2)]++;//�ش� ������ ���� �ø���
			}
		}

		for (int i = 0; i < types; i++)
			temp *= typearr[i];
		ans = temp - 1;

		cout << ans << "\n";
		
		temp = 1;
		types = ans = 0;
		str.clear();
	}

	return 0;
}