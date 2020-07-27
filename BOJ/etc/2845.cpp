//2845

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

	int a, b;
	cin >> a >> b;
	a = a * b;

	int arr[5];
	for (int i = 0; i < 5; i++) cin >> arr[i];

	for (int i = 0; i < 5; i++) cout << arr[i] - a << " ";

	return 0;
}