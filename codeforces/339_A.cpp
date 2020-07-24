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

	string s;
	cin >> s;
	vector<int> v;

	for (int i = 0; i < s.size(); i++) {
		if (i % 2 == 0) v.push_back(s[i] - '0');
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < v.size(); i++) {
		if (i == 0) cout << v[i];
		else cout << '+' << v[i];
	}

	return 0;
}