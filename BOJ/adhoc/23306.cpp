#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <cmath>
using namespace std;

typedef long long ll;

const int INF = 987654321;
const int MOD = 1000000007;

void FASTIO() {
    cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
}

int getResult(int first, int last) {
    if (first == last) return 0;
    if (first == 1) return -1;
    return 1;
}

int main() {
    FASTIO();

    int n, v; cin >> n;

    vector<int> arr;
    cout << "? 1\n" << flush;
    cin >> v;
    arr.push_back(v);

    cout << "? " << n << '\n' << flush;
    cin >> v;
    arr.push_back(v);

    cout << "! " << getResult(arr[0], arr[1]) << '\n' << flush;

    return 0;
}