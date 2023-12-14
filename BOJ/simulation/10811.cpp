#include <iostream>
#include <string>
#include <cstring>
#include <map>
#include <stack>
#include <algorithm>
#include <cmath>
using namespace std;

typedef long long ll;

vector<int> a;

void rev(int u, int v) {
    stack<int> st;
    for (int i=u; i<=v; i++) {
        st.push(a[i]);
    }

    for (int i=u; i<=v; i++) {
        a[i] = st.top(); st.pop();
    }
}

int main() {

    cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

    int n, m; cin >> n >> m;

    for (int i=1; i<=n; i++) {
        a.push_back(i);
    }

    while (m--) {
        int i, j; cin >> i >> j;
        rev(i-1, j-1);
    }

    for (auto& v : a) {
        cout << v << " ";
    }
    cout << '\n';

    return 0;
}