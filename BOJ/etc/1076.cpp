//1012

#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <deque>
#include <list>
#include <algorithm>
using namespace std;

int getfNum(string str){
	if (str.compare("black") == 0) return 0;
	else if (str.compare("brown") == 0) return 1;
	else if (str.compare("red") == 0) return 2;
	else if (str.compare("orange") == 0) return 3;
	else if (str.compare("yellow") == 0) return 4;
	else if (str.compare("green") == 0) return 5;
	else if (str.compare("blue") == 0) return 6;
	else if (str.compare("violet") == 0) return 7;
	else if (str.compare("grey") == 0) return 8;
	else if (str.compare("white") == 0) return 9;
}

long long int tten(int n) {
	long long int temp = 1;
	if (n == 0) return temp;
	else {
		for (int i = 1; i <= n; i++)
			temp *= 10;
	}

	return temp;
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	string str;
	int cnt = 0;
	long long int ans = 0;

	while (cnt != 3) {
		cin >> str;
		
		if (cnt != 2)
			ans = ans * 10 + getfNum(str);
		else
			ans *= tten(getfNum(str));

		cnt++;
	}

	cout << ans;

	return 0;
}