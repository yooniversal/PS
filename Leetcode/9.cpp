#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <map>
#include <stack>
#include <algorithm>
#include <cmath>
using namespace std;

typedef long long ll;

const int INF = 987654321;

int main() {

    cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

    ll n, m; cin >> n >> m;
    cout << n / m << '\n';
    cout << n % m << '\n';

    return 0;
}