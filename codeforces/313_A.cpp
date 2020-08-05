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

	int n; cin >> n;
	int result = n;
	result = max(result, n / 10);

	int a = n % 10;
	n /= 100;
	n = n * 10 + a;

	result = max(result, n);

	cout << result;

	return 0;
}