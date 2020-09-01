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
#define INF 987654321
#define MAX 100001
typedef long long ll;

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	string s; cin >> s;

	int start = 0;
	for (int i = 0; i < s.size(); i++) {
		if (!start && s[i] == 'h') ++start;
		else if (start == 1 && s[i] == 'e') ++start;
		else if (start == 2 && s[i] == 'l') ++start;
		else if (start == 3 && s[i] == 'l') ++start;
		else if (start == 4 && s[i] == 'o') {
			++start; break;
		}
	}

	if (start == 5) cout << "YES";
	else cout << "NO";

	return 0;
}