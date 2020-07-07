//11656

#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <vector>
#include <deque>
#include <queue>
#include <cmath>
#include <algorithm>
using namespace std;

vector<string> s;

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	//ios_base::sync_with_stdio(false);

	string str;
	int cnt = 0;

	cin >> str;
	int size = str.size();

	while (cnt != size) {
		s.push_back(str);
		str.erase(0, 1);
		cnt++;
	}

	sort(s.begin(), s.end());

	for (int i = 0; i < size; i++)
		cout << s[i] << '\n';

	return 0;
}