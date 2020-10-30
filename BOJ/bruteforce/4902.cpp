//4902
#include <bits/stdc++.h>
using namespace std;
#define INF 1000000001
#define MAX 1000001
#define MOD 1000000000
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

int n;
vector<ll> a, pSum;

ll solve(int cur) {
	ll ret = -INF;

	int row = 0; //ÇöÀç Çà
	for (row = 0; row < n; ++row)
		if (row * row <= cur && cur < (row + 1) * (row + 1))
			break;
	
	//°¢ Çà¿¡¼­ È¦/Â¦ ¹øÂ° Ã¼Å©
	bool even = true;
	if (row % 2) {
		if (cur % 2) even = false;
	}
	else
		if (cur % 2 == 0) even = false;

	//»ï°¢Çü (¿ª»ï°¢ÇüX)
	if (!even) {
		ll sum = a[cur];
		ret = max(ret, sum); //N=1
		for (int SIZE = 1; SIZE + row < n; ++SIZE) {
			int start = (row + SIZE) * (row + SIZE) + (cur - row * row);
			int end = (row + SIZE) * (row + SIZE) + (cur - row * row) + 2 * SIZE;
			sum += pSum[end] - pSum[start - 1];
			ret = max(ret, sum);
		}
	}
	//¿ª»ï°¢Çü
	else {
		ll sum = a[cur];
		ret = max(ret, sum); //N=1
		for (int SIZE = 1; row - SIZE >= 0 && cur - SIZE * 2 >= row * row && cur + SIZE * 2 < (row+1) * (row+1); ++SIZE) {
			int start = (row - SIZE) * (row - SIZE) + (cur - SIZE * 2 - row * row);
			int end = (row - SIZE) * (row - SIZE) + (cur - SIZE * 2 - row * row) + 2 * SIZE;
			sum += pSum[end] - pSum[start - 1];
			ret = max(ret, sum);
		}
	}
	return ret;
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int cnt = 0;
	while (1) {
		a.clear(); pSum.clear();

		cin >> n;
		if (n == 0) break;
		a.resize(n * n); pSum.resize(n * n);
		pSum[0] = a[0];
		ll ret = -INF;
		for (int i = 0; i < n * n; ++i) {
			cin >> a[i];
			if (i > 0) pSum[i] = pSum[i - 1] + a[i];
		}

		for (int i = 0; i < n * n; ++i) {
			ret = max(ret, solve(i));
		}
		cout << ++cnt << ". " << ret << '\n';
	}

	return 0;
}