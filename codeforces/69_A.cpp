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

int chk[26];

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, a, b, c, r1 = 0, r2 = 0, r3 = 0; cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a >> b >> c;
		r1 += a; r2 += b; r3 += c;
	}

	if (r1 == 0 && r2 == 0 && r3 == 0) cout << "YES";
	else cout << "NO";

	return 0;
}