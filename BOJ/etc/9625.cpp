//9625
#include <bits/stdc++.h>
using namespace std;
#define INF 1000000000
#define MAX 4000005
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int k; cin >> k;
	int a = 1, b = 0;
	for (int i = 0; i < k; ++i) {
		int tmp = b;
		b += a;
		a = tmp;
	}
	cout << a << " " << b;

	return 0;
}