//11444
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

vector<vector<ll>> operator*(const vector<vector<ll>>& a, const vector<vector<ll>>& b) {
	vector<vector<ll>> ret(a.size(), vector<ll>(b[0].size(), 0));
	for (int i = 0; i < a.size(); ++i)
		for (int j = 0; j < b.size(); ++j)
			for (int k = 0; k < b[0].size(); ++k)
				ret[i][k] = (ret[i][k] + a[i][j] * b[j][k]) % MOD;
	return ret;
}

vector<vector<ll>> pow(vector<vector<ll>> a, ll n) {
	vector<vector<ll>> ret(a.size(), vector<ll>(a.size(), 0));
	for (int i = 0; i < a.size(); ++i) ret[i][i] = 1;
	while (n > 0) {
		if (n & 1) ret = ret * a;
		n /= 2;
		a = a * a;
	}
	return ret;
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	ll n; cin >> n;
	vector<vector<ll>> Matrix(2, vector<ll>(2, 0));
	Matrix[0][0] = Matrix[0][1] = Matrix[1][0] = 1;
	Matrix = pow(Matrix, n-1);
	cout << Matrix[0][0] << '\n';

	return 0;
}