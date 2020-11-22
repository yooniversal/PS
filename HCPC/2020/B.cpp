#include <bits/stdc++.h>
using namespace std;
#define INF 1000000001
#define MAX 10000001
#define MOD 1000000000
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

bool prime[MAX], ret;
map<string, bool> chk;

void eratosthenes() {
	memset(prime, true, sizeof(prime));
	int SN = sqrt(MAX);
	for (int i = 2; i <= SN; ++i) {
		if (!prime[i]) continue;
		for (int j = i + i; j < MAX; j += i)
			prime[j] = false;
	}
	prime[1] = false;
}

void solve(string n){
	int tmp = stoi(n);
	if (chk[n]) return;
	chk[n] = true;
	if (n[0] != '0') {
		if (prime[tmp]) ret = true;
	}
	string next = n.substr(1) + n.front();
	solve(next);
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	eratosthenes();
	string n; cin >> n;
	chk[n] = true;
	solve(n.substr(1)+n.front());
	if (ret) cout << "YES";
	else cout << "NO";

	return 0;
}