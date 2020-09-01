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

	ll n, m, a; cin >> n >> m >> a;
	ll r1 = 0, r2 = 0;

	if (n % a) r1 = n / a + 1;
	else r1 = n / a;
	if (m % a) r2 = m / a + 1;
	else r2 = m / a;

	cout << r1 * r2;

	return 0;
}