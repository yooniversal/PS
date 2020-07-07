//2003

#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

int n, ans;
long long temp, m;
int arr[10001];

void dfs(int idx) {
	temp = 0;
	
	if (idx == n) return;
	for (int i = idx; i < n; i++)
		if (m > temp) {
			temp += arr[i];
			if (m == temp) {
				ans++;
				break;
			}
		}

	dfs(idx + 1);
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n >> m;

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	dfs(0);

	cout << ans;

	return 0;
}