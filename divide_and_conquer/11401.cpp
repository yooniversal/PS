//11401

#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <vector>
#include <deque>
#include <cmath>
#include <algorithm>
using namespace std;

long long pow(long long a, long long b, long long p) {
	if (b == 1) return a;
	else {
		long long tmp = pow(a, b / 2, p);
		tmp %= p;
		if (b % 2 == 0) return (tmp * tmp) % p;
		else return ((tmp * tmp)%p * a) % p;
	}
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, r;
	long long np=1, nrp=1, perm, p = 1000000007, ans=1;
	
	cin >> n >> r;

	//n!
	for (int i = 1; i <= n; i++) {
		np *= i;
		np %= p;
	}
	//r!
	for (int i = 1; i <= r; i++) {
		nrp *= i;
		nrp %= p;
	}
	//(n-r)!
	for (int i = 1; i <= n-r; i++) {
		nrp *= i;
		nrp %= p;
	}

	perm = pow(nrp, p - 2, p);
	perm %= p;

	ans = np * perm;
	ans %= p;
	cout << ans;

	return 0;
}