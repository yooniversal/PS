//9243

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

	int n;
	cin >> n;
	string a, b;
	cin >> a >> b;
	
	int cnt = 0;
	for (int i = 0; i < a.size(); i++) {
		if (a[i] == b[i]) cnt++;
	}

	if (n % 2 != 0)
		if (cnt == 0) cout << "Deletion succeeded";
		else cout << "Deletion failed";
	else
		if (cnt == a.size()) cout << "Deletion succeeded";
		else cout << "Deletion failed";

	return 0;
}