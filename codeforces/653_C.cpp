#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int t;
	cin >> t;
	while (t--) {
		int n, ans=0;
		string str;
		cin >> n >> str;
		
		int chk = 0; // chk should not be not-positive int
		int i=0;
		while(i != n){
			if (str[i] == '(') chk++;
			else chk--;
			if (chk < 0) {
				str += str[i];
				str.erase(i, 1);
				ans++;
				chk = 0;
			}
			else i++;
		}
		cout << ans << '\n';
	}

	return 0;
}