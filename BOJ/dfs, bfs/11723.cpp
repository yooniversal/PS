//11723

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
#define INF 1000000001
#define MAX 20001
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

bool chk[21];

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int m; cin >> m;
	while (m--) {
		string op;
		cin >> op;

		if (op == "add") {
			int num; cin >> num;
			if (chk[num]) continue;
			chk[num] = true;
		}
		else if (op == "check") {
			int num; cin >> num;
			if (chk[num]) cout << 1 << '\n';
			else cout << 0 << '\n';
		}
		else if (op == "remove") {
			int num; cin >> num;
			if (chk[num]) chk[num] = false;
		}
		else if (op == "toggle") {
			int num; cin >> num;
			if (chk[num]) chk[num] = false;
			else chk[num] = true;
		}
		else if (op == "all") {
			fill(chk, chk + 21, true);
		}
		else
			fill(chk, chk + 21, false);
	}

	return 0;
}