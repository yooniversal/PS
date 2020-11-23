//3687
#include <bits/stdc++.h>
using namespace std;
#define INF 1000000000
#define MAX 10001
#define MOD 1000000007
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

int cache[101], cache2[101];
int BIG[51], SMALL[51];
int digit[10] = { 6,2,5,5,4,5,6,3,7,6 };

//성냥 n개로 만들 수 있는 가장 큰 수의 길이
int f(int n) {
	if (n == 0) return 0;
	int& ret = cache[n];
	if (ret != -1) return ret;
	ret = 0;
	for (int S : {2, 3, 4, 5, 6, 7}) {
		if(n-S >= 0)
			ret = max(ret, f(n - S) + 1);
	}
	return ret;
}

//성냥 n개로 만들 수 있는 가장 작은 수의 길이
int g(int n) {
	if (n == 0) return 0;
	int& ret = cache2[n];
	if (ret != -1) return ret;
	ret = INF;
	for (int S : {2, 3, 4, 5, 6, 7}) {
		if(n-S>=0)
			ret = min(ret, g(n - S) + 1);
	}
	return ret;
}

void B_solve(int n, int p) {
	int maxLen = 0, number = -1;
	for (int i = 0; i <= 9; ++i) {
		if (p == 0 && i == 0) continue;
		if (n - digit[i] < 0) continue;
		if (maxLen < f(n - digit[i])+1) {
			maxLen = f(n - digit[i])+1;
			number = i;
		}
		else if (maxLen == f(n-digit[i])+1) {
			number = max(number, i);
		}
	}
	if (maxLen == 0) return;
	BIG[p] = number;
	B_solve(n - digit[number], p + 1);
}

void S_solve(int n, int p) {
	int minLen = INF, number = INF;
	for (int i = 0; i <= 9; ++i) {
		if (p == 0 && i == 0) continue;
		if (n - digit[i] < 0) continue;
		if (minLen > g(n - digit[i])) {
			minLen = g(n - digit[i]);
			number = i;
		}
	}
	if (minLen == INF) return;
	SMALL[p] = number;
	S_solve(n - digit[number], p + 1);
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int t; cin >> t;
	while (t--) {
		memset(cache, -1, sizeof(cache));
		memset(cache2, -1, sizeof(cache2));
		int n; cin >> n;
		B_solve(n, 0); S_solve(n, 0);
		for (int i = 0; i < g(n); ++i) cout << SMALL[i];
		cout << ' ';
		for (int i = 0; i < f(n); ++i) cout << BIG[i];
		cout << '\n';
	}

	return 0;
}