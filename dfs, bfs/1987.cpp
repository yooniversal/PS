//1987

#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

char arr[21][21];
vector<char> alphabet;
int r, c, ans, subans;

//������ ���ڰ� �ִ��� üũ���ִ� �Լ�
bool checkalpha(char alpha) {
	for (int i = 0; i < alphabet.size(); i++)
		if (alpha == alphabet[i])
			return true;
	return false;
}

void dfs(int x, int y) {

	//���� ����
	if (x < 0 || x > r - 1 || y < 0 || y > c - 1 || ans>25) {	//���ĺ��� �ִ� 26���� ans=26�� ����
		return;
	}
	else {
		//���� ���ĺ��� �ְ� ����
		alphabet.push_back(arr[x][y]);
		subans++;

		//�����¿�
		if (checkalpha(arr[x - 1][y]) == false) dfs(x - 1, y);
		if (checkalpha(arr[x][y - 1]) == false) dfs(x, y - 1);
		if (checkalpha(arr[x + 1][y]) == false) dfs(x + 1, y);
		if (checkalpha(arr[x][y+1]) == false) dfs(x, y + 1);
		
		//�ִ� ����
		//���������� ���� ���ĺ� ����
		ans = max(ans, subans);
		alphabet.pop_back();
		subans--;
	}
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> r >> c;
	for (int n = 0; n < r; n++)
		for (int j = 0; j < c; j++)
			cin >> arr[n][j];
	
	dfs(0, 0);

	cout << ans;

	return 0;
}