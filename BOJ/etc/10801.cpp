//10801

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

	vi a(10), b(10);
	for (int i = 0; i < 10; i++) cin >> a[i];
	for (int i = 0; i < 10; i++) cin >> b[i];

	int r1 = 0, r2 = 0;
	for (int i = 0; i < 10; i++) {
		if (a[i] > b[i]) r1++;
		else if (a[i] < b[i]) r2++;
	}

	if (r1 == r2) cout << "D";
	else if (r1 > r2) cout << "A";
	else cout << "B";

	return 0;
}