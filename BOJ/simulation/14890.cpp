//14890
#include <bits/stdc++.h>
using namespace std;
#define INF 1000000001
#define MAX 101
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

int n, l;
int a[101][101];
bool slope[101];

bool OOB(int x) {
	if (x < 0 || x >= n) return true;
	return false;
}

bool sweeping(int num, bool row) {
	memset(slope, 0, sizeof(slope));
	bool ret = true;
	if (row) {
		//오른쪽으로 스위핑
		for (int i = 0; i < n - 1; ++i)
			if (a[num][i] < a[num][i + 1]) {
				if (a[num][i + 1] - a[num][i] > 1) return false;
				//경사로 놓기
				for (int j = i; j >= i - l + 1; --j) {
					if (OOB(i - l + 1)) return false;
					if (a[num][i] != a[num][j]) return false;
					slope[j] = true;
				}
			}
		//왼쪽으로 스위핑
		for (int i = n - 1; i >= 1; --i) {
			if (a[num][i - 1] > a[num][i]){
				if (a[num][i - 1] - a[num][i] > 1) return false;
				//경사로 놓기
				for (int j = i; j <= i + l - 1; ++j) {
					if (OOB(i + l - 1)) return false;
					if (slope[j]) return false;
					if (a[num][i] != a[num][j]) return false;
					slope[j] = true;
				}
			}
		}
	}
	else {
		//아래로 스위핑
		for (int i = 0; i < n-1; ++i)
			if (a[i][num] < a[i+1][num]){
				if (a[i+1][num] - a[i][num] > 1) return false;
				//경사로 놓기
				for (int j = i; j >= i - l + 1; --j) {
					if (OOB(i - l + 1)) return false;
					if (a[i][num] != a[j][num]) return false;
					slope[j] = true;
				}
			}
		for (int i = n - 1; i >= 1; --i) {
			if (a[i][num] < a[i-1][num]){
				if (a[i-1][num] - a[i][num] > 1) return false;
				//경사로 놓기
				for (int j = i; j <= i + l - 1; ++j) {
					if (OOB(i + l - 1)) return false;
					if (slope[j]) return false;
					if (a[i][num] != a[j][num]) return false;
					slope[j] = true;
				}
			}
		}
	}
	return true;
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n >> l;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			cin >> a[i][j];

	int ret = 0;
	for (int i = 0; i < n; ++i)
		if (sweeping(i, true))
			++ret;
	for (int i = 0; i < n; ++i)
		if (sweeping(i, false))
			++ret;
	cout << ret;

	return 0;
}