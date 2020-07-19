//2857

#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <cmath>
#include <algorithm>
#include <map>
using namespace std;

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	string str;
	vector<int> ans;
	
	for (int i = 0; i < 5; i++) {
		cin >> str;
		int F = 0, B = 0;
		for (int j = 0; j < str.size(); j++) {
			if (str[j] == 'F' || str[j] == 'B' || str[j] == 'I') {
				if (str[j] == 'F') {
					F = 1;
				}

				if (str[j] == 'B') {
					if (F) B = 1;

				}

				if (str[j] == 'I') {
					if (F && B) {
						ans.push_back(i + 1);
						break;
					}
				}
			}
			else {
				F = 0; B = 0;
			}
		}
	}

	if (ans.size() == 0) cout << "HE GOT AWAY!";
	else {
		for (int i = 0; i < ans.size(); i++) cout << ans[i] << " ";
	}

	return 0;
}