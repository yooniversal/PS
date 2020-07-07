//1032

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

	int n;
	string str, save;

	cin >> n;

	while (n--) {
		cin >> str;
		
		if (save == "")
			save = str;
		else {
			for (int i = 0; i < str.size(); i++)
				if (save[i] == str[i])
					continue;
				else
					save[i] = '?';
		}
	}

	cout << save;

	return 0;
}