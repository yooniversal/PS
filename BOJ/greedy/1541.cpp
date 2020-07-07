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
		//-가 걸리지 않을 때
		if (opch == false) {
			if (str[i] == '+') {		//계속 +만 나오는 상황이므로 계속 더해준다
				ans += temp;
				temp = 0;
			}
			else if (str[i] == '-') {
				opch = true;			//-가 나오면 다 빼라는 말이므로 모드를 바꿔준다
				ans += temp;			//일단 앞에까지는 +이므로 더해준다
				temp = 0;
			}
			else {
				temp = temp * 10 + (str[i] - '0');	
				if (i == str.length() - 1)
					ans += temp;
			}
		}
		//-가 걸릴 때
		else if(opch == true) {
			if (str[i] == '+') {
				ans -= temp;
				temp = 0;
			}
			else if (str[i] == '-') {	//-가 최소 한 번 나온 이상 다 빼버려도 된다
				ans -= temp;			//따라서 -가 나와도 모드를 바꿔주지 않는다
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