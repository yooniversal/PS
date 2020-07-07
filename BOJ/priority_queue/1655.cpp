//1655

#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <vector>
#include <deque>
#include <queue>
#include <cmath>
#include <algorithm>
#include <functional>
using namespace std;

priority_queue<int> maxheap;
priority_queue<int, vector<int>, greater<int>> minheap;
int heap_size;

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int t, tmp;

	cin >> t;
	while (t--) {
		cin >> tmp;
		if (heap_size % 2 == 0) {
			maxheap.push(tmp);
			heap_size++;
		}
		else {
			minheap.push(tmp);
			heap_size++;
		}

		if (heap_size > 1 && maxheap.top() > minheap.top()) {
			int maxval = maxheap.top();
			int changeval = minheap.top();
			maxheap.pop(); minheap.pop();
			maxheap.push(changeval); minheap.push(maxval);
		}

		cout << maxheap.top() << '\n';
	}

	return 0;
}