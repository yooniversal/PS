//2804

#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <vector>
#include <deque>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	string str1, str2;
	int point1 = 31, point2;
	char arr[31][31];

	cin >> str1 >> str2;
	for(int i=0; i<str1.size(); i++)
		for(int j=0; j<str2.size(); j++)
			if (str1[i] == str2[j]) {
				point1 = i;
				point2 = j;
				i = str1.size();
				j = str2.size();
			}

	for (int i = 0; i < str2.size(); i++) {
		for (int j = 0; j < str1.size(); j++) {
			if (i == point2) cout << str1[j];
			else {
				if (j == point1) cout << str2[i];
				else cout << ".";
			}
		}
		cout << '\n';
	}
	
	return 0;
}