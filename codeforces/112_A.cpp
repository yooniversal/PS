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

typedef long long ll;

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	string s1, s2;
	cin >> s1 >> s2;
	
	for (int i = 0; i < s1.size(); i++) {
		if ('A' <= s1[i] && s1[i] <= 'Z') s1[i] = s1[i] - 'A' + 'a';
		if ('A' <= s2[i] && s2[i] <= 'Z') s2[i] = s2[i] - 'A' + 'a';
		if (s1[i] > s2[i]) {
			cout << "1";
			return 0;
		}
		else if (s1[i] < s2[i]) {
			cout << "-1";
			return 0;
		}
	}
	cout << "0";

	return 0;
}