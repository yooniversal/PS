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

	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<int> v(n);
		for (int i = 0; i < n; i++) cin >> v[i];
		for (int i = n - 1; i >= 0; i--) cout << v[i] << " ";
		cout << '\n';
	}

	return 0;
}