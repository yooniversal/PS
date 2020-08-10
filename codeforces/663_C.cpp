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
#define MAXSIZE 1000001
#define mod 1000000007LL

int per[MAXSIZE], po[MAXSIZE];

long long pow(long long a, long long b, long long c) {
	long long t;

	if (b == 1) return a;
	else {
		t = pow(a, b / 2, c)%mod;
		if (b % 2 == 1) return ((t * t) % c * a) % c;
		else return (t * t) % c;
	}
}

ll per2(ll n) {
	if (n == 1) return n;
	else {
		ll res = n;
		for (ll i = n - 1; i > 0; i--)
			res = (res*i)%mod;
		return res;
	}
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	ll n; cin >> n;
	ll two = pow(2%mod, n-1, mod)%mod;
	ll dd = per2(n);
	if (dd < two) {
		cout << (per2(n - 1) * n - two)%mod << '\n';
	}
	else cout << dd - two << '\n';

	return 0;
}