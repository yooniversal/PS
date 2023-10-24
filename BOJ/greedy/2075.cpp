#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int, int> ii;

int n;

int main () {

    cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

    cin >> n;

    const int len = n*n;
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i=0; i<len; ++i) {
        int v; cin >> v;
        if(pq.size() < n) {
            pq.push(v);
            continue;
        }

        if(pq.top() >= v) continue;
        pq.pop();
        pq.push(v);
    }

    cout << pq.top() << '\n';

    return 0;
}