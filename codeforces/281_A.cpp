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
	
	if ('a' <= s[0] && s[0] <= 'z') s[0] = s[0] - 'a' + 'A';
	cout << s;

	return 0;
}