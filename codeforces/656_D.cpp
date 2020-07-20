#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
using namespace std;


string str;
int cnt(int l, int r, char c) {
	int ans = 0;
	for (int i = l; i <= r; i++)
		if (str[i] == c) ans++;
	return ans;
}

int process(int l, int r, char c) {
	if (l > r) return 0;
	if (l == r) {
		if (str[l] == c) return 0;
		else return 1;
	}

	int mid = (l + r) / 2;
	//오른쪽 절반에서 char와 다른 것 + 왼쪽 절반에서 solve
	int cntl = (r-l+1)/2 - cnt( mid+1, r, c) + process(l, mid, c + 1);
	//왼쪽 절반에서 char와 다른 것 + 오른쪽 절반에서 solve
	int cntr = (r-l+1)/2 - cnt(l, mid, c) + process(mid+1, r, c + 1);
	return min(cntl, cntr);	//양 케이스중 최솟값
}

int main() {
	
	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n >> str;
		cout << process(0, n-1, 'a') << '\n';
	}

	return 0;
}