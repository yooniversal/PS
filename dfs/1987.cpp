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

//지나간 문자가 있는지 체크해주는 함수
bool checkalpha(char alpha) {
	for (int i = 0; i < alphabet.size(); i++)
		if (alpha == alphabet[i])
			return true;
	return false;
}

void dfs(int x, int y) {

	//종료 조건
	if (x < 0 || x > r - 1 || y < 0 || y > c - 1 || ans>25) {	//알파벳은 최대 26개라 ans=26면 종료
		return;
	}
	else {
		//지난 알파벳을 넣고 시작
		alphabet.push_back(arr[x][y]);
		subans++;

		//상하좌우
		if (checkalpha(arr[x - 1][y]) == false) dfs(x - 1, y);
		if (checkalpha(arr[x][y - 1]) == false) dfs(x, y - 1);
		if (checkalpha(arr[x + 1][y]) == false) dfs(x + 1, y);
		if (checkalpha(arr[x][y+1]) == false) dfs(x, y + 1);
		
		//최댓값 갱신
		//마지막으로 지난 알파벳 제거
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