//10768

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
#define MAX 2020
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int m, d; cin >> m >> d;
	if (m < 2) cout << "Before";
	else if (m > 2) cout << "After";
	else {
		if (d < 18) cout << "Before";
		else if (d > 18) cout << "After";
		else cout << "Special";
	}
	return 0;
}