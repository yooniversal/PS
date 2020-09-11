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
		int x, y; cin >> x >> y;
		for (int i = 1; i <= y - x; i++) {
			if ((y - x) % i) continue;
			int ret = 1 + (y - x) / i;
			if (ret > n) continue;
			if (ret == n) {
				while (x <= y) { cout << x << " "; x += i; } cout << '\n';
				break;
			}
			ret += x / i-1;
			if (ret >= n) {
				int cnt = 0;
				for (int a = x; y >= a; a += i) { cout << a << " "; cnt++; }
				while (x-i>0 && cnt != n) { x -= i; cout << x << " "; cnt++; } cout << '\n';
				break;
			}
			else {
				int cnt = 0;
				for (int a = x; y >= a; a += i) { cout << a << " "; cnt++; }
				while (x - i > 0) { x -= i; cout << x << " "; cnt++; }
				while (cnt != n) { y += i; cout << y << " "; cnt++; } cout << '\n';
				break;
			}
		}
	}

	return 0;
}